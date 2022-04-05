#include <estacion1.hpp>
#include <estacion2.hpp>
#include <estacion3.hpp>
#include <estacion4.hpp>
#include <iostream>

static double L1 = 3.0;
static double M1 = 5;
static double D1 = 2.5;
static double M2 = 4.0;
static double D2 = 1.5;
static double M3 = 4.0;
static double D3 = 1.5;
static double M4 = 5.0;
static double D4 = 2.0;

void consumidor(std::shared_ptr<CadenaDeTraslado> cadena_final,
                std::shared_ptr<CadenaDeTraslado> cadena_traslado_1a2,
                std::shared_ptr<CadenaDeTraslado> cadena_traslado_2a3,
                std::shared_ptr<CadenaDeTraslado> cadena_traslado_3a4)
{
    while (true)
    {
        auto temp_log = cadena_traslado_1a2->obtener_log();
        if (not temp_log.empty())
            std::cout << temp_log << std::endl;

        temp_log = cadena_traslado_2a3->obtener_log();
        if (not temp_log.empty())
            std::cout << cadena_traslado_2a3->obtener_log() << std::endl;

        temp_log = cadena_traslado_3a4->obtener_log();
        if (not temp_log.empty())
            std::cout << temp_log << std::endl;

        auto carro = std::move(cadena_final->obtener_carro_actual());
        if (carro != nullptr)
        {
            std::cout << "\n---Se ha ensamblado correctamente un carro---" << std::endl;
            std::cout << "Carro ID: " << carro->get_id() << " ¡Listo para conducirlo!" << std::endl;
            std::cout << "Pintura: " << color[carro->get_color()] << std::endl;
            std::cout << "Modelo del carro: " << car_model[carro->get_car_model()] << std::endl;
            std::cout << "Motor: " << motor_model[carro->get_motor_model()] << std::endl;
            std::cout << "Asientos: " << seats_model[carro->get_seats_model()] << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void observador(unsigned seed,
                std::shared_ptr<CadenaDeTraslado> cadena_llegada)
{
    std::mt19937 generador(seed);
    std::poisson_distribution<int> tiempo_llegada(L1);

    while (true)
    {
        auto intervalo_llegada = tiempo_llegada(generador);
        std::this_thread::sleep_for(std::chrono::seconds(intervalo_llegada + 1));

        auto carro = std::make_unique<Carro>();
        cadena_llegada->insertar_carro(std::move(carro));
    }
}

int main(int argc, char const *argv[])
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto cadena_llegada = std::make_shared<CadenaDeTraslado>();
    auto cadena_traslado_1a2 = std::make_shared<CadenaDeTraslado>();
    auto cadena_traslado_2a3 = std::make_shared<CadenaDeTraslado>();
    auto cadena_traslado_3a4 = std::make_shared<CadenaDeTraslado>();
    auto cadena_traslado_final = std::make_shared<CadenaDeTraslado>();

    auto estacion1 = Estacion1(seed, M1, D1, cadena_llegada, cadena_traslado_1a2);
    auto estacion2 = Estacion2(seed, M2, D2, cadena_traslado_1a2, cadena_traslado_2a3);
    auto estacion3 = Estacion3(seed, M3, D3, cadena_traslado_2a3, cadena_traslado_3a4);
    auto estacion4 = Estacion4(seed, M4, D4, cadena_traslado_3a4, cadena_traslado_final);

    std::thread proceso_observador(&observador,
                                   seed,
                                   cadena_llegada);
    std::thread proceso_estacion_1(&Estacion1::worker, &estacion1);
    std::thread proceso_estacion_2(&Estacion2::ejecutar, &estacion2);
    std::thread proceso_estacion_3(&Estacion3::worker, &estacion3);
    std::thread proceso_estacion_4(&Estacion4::ejecutar, &estacion4);
    std::thread proceso_consumidor(&consumidor, cadena_traslado_final,
                                   cadena_traslado_1a2,
                                   cadena_traslado_2a3,
                                   cadena_traslado_3a4);

    std::cout << "¡Bienvenido a la Ensambladadora V! Para finalizar el programa: Ctrl+C to exit.\n";

    if (proceso_observador.joinable())
        proceso_observador.join();

    if (proceso_estacion_1.joinable())
        proceso_estacion_1.join();

    if (proceso_estacion_2.joinable())
        proceso_estacion_2.join();

    if (proceso_estacion_3.joinable())
        proceso_estacion_3.join();

    if (proceso_estacion_4.joinable())
        proceso_estacion_4.join();

    if (proceso_consumidor.joinable())
        proceso_consumidor.join();

    return 0;
}
