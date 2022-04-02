#include <estacion1.hpp>
#include <iostream>

static double L1 = 3.0;
static double M1 = 0.5;
static double D1 = 1.0;

int main(int argc, char const *argv[])
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto cadena_traslado_1a2 = std::make_shared<CadenaDeTraslado>();
    auto estacion1 = Estacion1(seed, L1, M1, D1, cadena_traslado_1a2);
    std::thread proceso_estacion_1(&Estacion1::worker, &estacion1);

    std::cout << "Press Ctrl+D to exit. \n";

    while (std::cin)
    {
        proceso_estacion_1.join();
    }

    return 0;
}