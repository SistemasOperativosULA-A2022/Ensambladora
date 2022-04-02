#include <estacion1.hpp>
#include <iostream>

/**
 * @brief Construct a new Estacion 1:: Estacion 1 object
 *
 * @param seed Seed for random generator
 * @param L1 Parametro lambda
 * @param M1 Media 1
 * @param D1 Desviación Estandar 1
 * @param cadena_traslado Cadena de traslado entre estación 1 y 2
 */
Estacion1::Estacion1(
    unsigned seed,
    double L1,
    double M1, double D1,
    std::shared_ptr<CadenaDeTraslado> cadena_traslado) : generador{seed},
                                                         tiempo_llegada{L1},
                                                         tiempo_procesamiento{M1, D1},
                                                         cadena_traslado{cadena_traslado},
                                                         id_counter{0}

{
}

Estacion1::~Estacion1()
{
    cadena_traslado.reset();
}

void Estacion1::worker()
{
    while (true)
    {
        auto intervalo_llegada = this->tiempo_llegada(this->generador);
        std::cerr << "Intervalo de llegada: " << intervalo_llegada << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(intervalo_llegada));
        
        auto carro = std::make_unique<Carro>(++id_counter);
        this->cadena_traslado->insertar_carro(std::move(carro));
    }
}