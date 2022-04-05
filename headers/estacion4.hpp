#ifndef __ESTACION_4_HEADER__
#define __ESTACION_4_HEADER__ 

#include <chrono>
#include <random>
#include <thread>

#include <cadena_traslado.hpp>

class Estacion4
{
private:
    std::mt19937 generador;
    std::normal_distribution<double> tiempo_procesamiento;
    std::shared_ptr<CadenaDeTraslado> cadena_traslado3a4;
    std::shared_ptr<CadenaDeTraslado> cadena_traslado_final;
public:
    Estacion4() = default;
    Estacion4(double seed, double M4, double D4, std::shared_ptr<CadenaDeTraslado> c3a4, std::shared_ptr<CadenaDeTraslado> cf);
    ~Estacion4() = default;
    
    void ejecutar();
};

#endif // __ESTACION_4_HEADER__
