#include <estacion3.hpp>

#include <iostream>

/**
 * @brief Construye una nueva Estacion 4
 *
 * @param seed Semilla para el generador de numeros aleatorio
 * @param M2 Media 2
 * @param D2 Desviación Estandar 2
 * @param carro Carro recibido desde la estacion 1
 */
Estacion3::Estacion3(
    unsigned seed,
    double M2,
    double D2,
    std::shared_ptr<CadenaDeTraslado> c2a3,
    std::shared_ptr<CadenaDeTraslado> c3a4) : generador(seed),
                                              tiempo_procesamiento(M2, D2),
                                              cadena_traslado_2a3(c2a3),
                                              cadena_traslado_3a4(c2a3)
{
    // empty
}

/**
 * @brief Hilo infinito que duerme el intervalo de segundo obtenido a través de
 * la distriubción normal (tiempo de procesamiento), se procede a pintar
 * los carros llegados de la estacion 2.
 */
void Estacion3::worker()
{
    while (true)
    {
        auto carro = std::move(cadena_traslado_2a3->obtener_carro_actual());
        // auto volumen = 600;

        if (carro != nullptr)
        {
            double intervalo_procesamiento = tiempo_procesamiento(generador);

            std::cerr << "Llego a la Estacion 2 el carro con ID: " << carro->get_id() << '\n';
            std::cerr << "Tiempo de procesamiento Estacion 2 carro con ID " << carro->get_id() << ": " << intervalo_procesamiento << '\n';

            std::this_thread::sleep_for(std::chrono::seconds(int(intervalo_procesamiento) + 1));

            // Modifica carro aquí

            std::cerr << "Saliendo de la Estacion 3 el carro con ID:" << carro->get_id() << '\n';
            std::cerr << "Color=: " << carro->get_color() << '\n';
            std::cerr << "Modelo= " << carro->get_car_model() << '\n';
            ;
            cadena_traslado_3a4->insertar_log("Completado correctamente Estacion3 carro con ID: " + carro->get_id());
            cadena_traslado_3a4->insertar_carro(std::move(carro));
        }
    }
}