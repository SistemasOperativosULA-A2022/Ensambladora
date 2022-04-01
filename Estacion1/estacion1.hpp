#ifndef ESTACION_1_HEADER
#define ESTACION_1_HEADER

#include <chrono>
#include <random>

class Estacion1
{
private:
    std::default_random_engine generador;
    std::normal_distribution<double> tiempo_procesamiento;
    std::poisson_distribution<double> tiempo_llegada;

public:
    Estacion1(double L1, double M1, double);
    ~Estacion1();
};

#endif // ESTACION_1_HEADER