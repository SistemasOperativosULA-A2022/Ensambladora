#include <estacion1.hpp>
#include <estacion4.hpp>

#include <iostream>

static double L1 = 3.0;
static double M1 = 5;
static double D1 = 2.5;
static double M4 = 5.0;
static double D4 = 2.0;

void consumer(std::shared_ptr<CadenaDeTraslado> cadena, std::shared_ptr<CadenaDeTraslado> cadena34)
{
    while (true)
    {
        auto carro = std::move(cadena->obtener_carro_actual());
        if (carro != nullptr)
        {
            std::cout << "Sacado de la cola: " << carro->get_id() << std::endl;
            cadena34->insertar_carro(std::move(carro));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main(int argc, char const *argv[])
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto cadena_traslado_1a2 = std::make_shared<CadenaDeTraslado>();
    auto estacion1 = Estacion1(seed, L1, M1, D1, cadena_traslado_1a2);
    
    auto cadena_traslado_3a4 = std::make_shared<CadenaDeTraslado>();
    auto estacion4 = Estacion4(seed, M4, D4, cadena_traslado_3a4);
    
    std::thread proceso_estacion_1(&Estacion1::worker, &estacion1);
    std::thread consumidor_cadena(&consumer, cadena_traslado_1a2, cadena_traslado_3a4);

    std::thread proceso_estacion_4(&Estacion4::ejecutar, &estacion4);
    
    std::cout << "Press Ctrl+C to exit. \n";

    if (proceso_estacion_1.joinable())
        proceso_estacion_1.join();
    if (consumidor_cadena.joinable())
        proceso_estacion_1.join();
    if (proceso_estacion_4.joinable())
        proceso_estacion_4.join();
    
    while (std::cin);

    return 0;
}
