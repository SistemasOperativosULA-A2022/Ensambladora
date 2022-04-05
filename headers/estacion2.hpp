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
    std::shared_ptr<CadenaDeTraslado> cadena_traslado;
    int prev_color;
public:
    Estacion2() = default;
    Estacion2(double seed, double M2, double D2, std::shared_ptr<CadenaDeTraslado> c);
    ~Estacion2() = default;
    
    void ejecutar();
};

#endif // __ESTACION_2_HEADER__
