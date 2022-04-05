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
    double M1, double D1,
    std::shared_ptr<CadenaDeTraslado> cadena_llegada,
    std::shared_ptr<CadenaDeTraslado> cadena_traslado) : generador{seed},
                                                        tiempo_procesamiento{M1, D1},
                                                        cadena_llegada{cadena_llegada},
                                                        cadena_traslado1a2{cadena_traslado},
                                                        id_counter{0}

{
}

/**
 * @brief Hilo infinito que duerme el intervalo de segundo obtenido a través de
 * la distriubción de Poisson (Tiempo de llegada)
 *
 */
void Estacion1::worker()
{
    long long counter = 0;
    while (true)
    {
        auto carro = std::move(this->cadena_llegada->obtener_carro_actual());
        if (carro == nullptr)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }

        auto intervalo_procesamiento = this->tiempo_procesamiento(this->generador);
        intervalo_procesamiento = std::abs(intervalo_procesamiento);
        std::cerr << "Tiempo de procesamiento en Estación1: " << intervalo_procesamiento << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(int(intervalo_procesamiento) + 1));

        counter++;
        carro->set_id(counter);
        std::cerr << "Asignando ID al carro recibido: " << carro->get_id() << std::endl;

        this->cadena_traslado1a2->insertar_log("Completado correctamente Estacion1 carro con ID: " + carro->get_id());
        this->cadena_traslado1a2->insertar_carro(std::move(carro));
    }
}