/**
 * @file estacion3.hpp
 * @author Josmar Muñoz (josmaralejandro97@gmail.com)
 * @version 0.1
 * @date 2022-04-02
 */

#ifndef __ESTACION_3_HEADER__
#define __ESTACION_3_HEADER__

#include <chrono>
#include <random>
#include <thread>
#include <cadena_traslado.hpp>

class Estacion3
{
private:
    std::mt19937 generador;
    std::normal_distribution<double> tiempo_procesamiento;
    std::shared_ptr<CadenaDeTraslado> cadena_traslado_2a3;
    std::shared_ptr<CadenaDeTraslado> cadena_traslado_3a4;


    unsigned long long id_counter;

public:
    Estacion3(unsigned, double, double, std::shared_ptr<CadenaDeTraslado>,
    std::shared_ptr<CadenaDeTraslado>);
    ~Estacion3() = default;
    Estacion3() = delete;

    void worker();
};

#endif // __ESTACION_1_HEADER__