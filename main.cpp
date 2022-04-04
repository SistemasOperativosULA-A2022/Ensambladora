#include <estacion1.hpp>
#include <iostream>

static double L1 = 3.0;
static double M1 = 5;
static double D1 = 2.5;

void consumer(std::shared_ptr<CadenaDeTraslado> cadena)
{
    while (true)
    {
        auto carro = std::move(cadena->obtener_carro_actual());
        if (carro != nullptr)
        {
            std::cout << "\n---Se ha completado un carro---" << std::endl;
            std::cout << "El carro ID: " << carro->get_id() << "se ha emsablado con éxito!" << std::endl;
            std::cout << "Pintura: " << carro->get_volume() << std::endl;
            std::cout << "Modelo del carro: " << carro->get_car_model() << std::endl;
            std::cout << "Motor: " << carro->get_motor_model() << std::endl;
            std::cout << "Asientos: " << carro->get_seats_model() << std::endl;
            std::cout << "---------------------------------" << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main(int argc, char const *argv[])
{
    int prod = 0;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto cadena_traslado_1a2 = std::make_shared<CadenaDeTraslado>();
    auto cadena_traslado_2a3 = std::make_shared<CadenaDeTraslado>();
    auto cadena_traslado_3a4 = std::make_shared<CadenaDeTraslado>();
    auto estacion1 = Estacion1(seed, L1, M1, D1, cadena_traslado_1a2);
    // auto estacion2 = Estacion2(seed, M2, D2, cadena_traslado_1a2, cadena_traslado_2a3);
    // auto estacion3 = Estacion3(seed, M3, D3, cadena_traslado_2a3, cadena_traslado_3a4);
    // auto estacion4 = Estacion4(seed, M4, D4, cadena_traslado_3a4);
    
    std::cout << "Para finalizar el programa: Ctrl+C to exit.\n";

    while (true)
    {
        auto carro = std::make_unique<Carro>(++prod);
        std::thread proceso_estacion_1(&Estacion1::worker, &estacion1);
        // std::thread proceso_estacion_2(&Estacion2::worker, &estacion2);
        // std::thread proceso_estacion_3(&Estacion3::worker, &estacion3);
        // std::thread proceso_estacion_4(&Estacion4::worker, &estacion4);
        std::thread consumidor_cadena(&consumer, cadena_traslado_1a2);
        
        cadena_traslado_1a2->insertar_carro(std::move(carro));

        if (proceso_estacion_1.joinable())
            proceso_estacion_1.join();

        std::cout << "\n"
                  << cadena_traslado_1a2->mostrar_cadena(1) << std::endl;
        /*
        if (proceso_estacion_2.joinable())
            proceso_estacion_2.join();

        std::cout << "\n" << cadena_traslado_2a3->mostrar_cadena(2) << std::endl;

        if (proceso_estacion_3.joinable())
            proceso_estacion_3.join();

        std::cout << "\n" << cadena_traslado_3a4->mostrar_cadena(3) << std::endl;

        if (proceso_estacion_4.joinable())
            proceso_estacion_4.join();
        if (consumidor_cadena.joinable())
            consumidor_cadena.join();*/
    }

    std::cout << "\nTotal de carros ensamblados completamente: " << cadena_traslado_3a4->get_produccion() << std::endl;

    return 0;
}