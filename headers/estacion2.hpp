#ifndef __ESTACION_2_HEADER__
#define __ESTACION_2_HEADER__ 

#include <chrono>
#include <random>
#include <thread>

#include <cadena_traslado.hpp>

const std::string color[11] = { "Negro", "Azul", "Marron", "Gris", 
    "Verde", "Naranja", "Rosa", "Purpura", "Rojo", "Blanco", "Amarrillo" };

const std::string car_model[2] = { "Coupe", "Sedan" };

class Estacion2
{
private:
    std::mt19937 generador;
    std::normal_distribution<double> tiempo_procesamiento;
    std::shared_ptr<CadenaDeTraslado> cadena_traslado_1a2;
    std::shared_ptr<CadenaDeTraslado> cadena_traslado_2a3;
    int prev_color;
    
public:
    Estacion2() = default;
    Estacion2(unsigned, double, double, std::shared_ptr<CadenaDeTraslado>, 
    std::shared_ptr<CadenaDeTraslado>);
    ~Estacion2() = default;
    
    void ejecutar();
};

#endif // __ESTACION_2_HEADER__
