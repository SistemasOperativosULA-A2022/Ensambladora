#ifndef __ESTACION_4_HEADER__
#define __ESTACION_4_HEADER__ 

#include <chrono>
#include <random>
#include <thread>

#include <cadena_traslado.hpp>

const std::string seats_model[2] = { "Tela", "Cuero" };

class Estacion4
{
private:
    std::mt19937 generador;
    std::normal_distribution<double> tiempo_procesamiento;
    std::shared_ptr<CadenaDeTraslado> cadena_traslado;
public:
    Estacion4() = default;
    Estacion4(double seed, double M4, double D4, std::shared_ptr<CadenaDeTraslado> c);
    ~Estacion4() = default;
    
    void ejecutar();
};

#endif // __ESTACION_4_HEADER__
