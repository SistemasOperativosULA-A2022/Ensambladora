/**
 * @file cadena_traslado.hpp
 * @author Jorge Luis Rodríguez González (egroj97@gmail.com)
 * @version 0.1
 * @date 2022-04-02
 */

#ifndef __ESTACION_1_HEADER__
#define __ESTACION_1_HEADER__

#include <chrono>
#include <random>
#include <thread>
#include <cadena_traslado.hpp>

class Estacion1
{
private:
    std::mt19937 generador;
    std::normal_distribution<double> tiempo_procesamiento;
    std::poisson_distribution<int> tiempo_llegada;
    std::shared_ptr<CadenaDeTraslado> cadena_traslado;

    unsigned long long id_counter;

public:
    Estacion1(unsigned, double, double, double, std::shared_ptr<CadenaDeTraslado>);
    ~Estacion1() = default;
    Estacion1() = delete;

    void worker();
};

#endif // __ESTACION_1_HEADER__