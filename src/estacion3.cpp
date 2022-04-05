#include <estacion3.hpp>

#include <iostream>

/**
 * @brief Construye una nueva Estacion 3
 *
 * @param seed Semilla para el generador de numeros aleatorio
 * @param M3 Media 3
 * @param D3 Desviación Estandar 3
 * @param carro Carro recibido desde la estacion 1
 */
Estacion3::Estacion3(
    unsigned seed,
    double M3,
    double D3,
    std::shared_ptr<CadenaDeTraslado> c2a3,
    std::shared_ptr<CadenaDeTraslado> c3a4) : generador(seed),
                                              tiempo_procesamiento(M3, D3),
                                              cadena_traslado_2a3(c2a3),
                                              cadena_traslado_3a4(c2a3)
{
    // empty
}

/**
 * @brief Hilo infinito que duerme el intervalo de segundo obtenido a través de
 * la distriubción normal (tiempo de procesamiento), se procede a la colocación del motor y el cableado.
 * A la tarjeta del automóvil se agrega el tipo de motor colocado además si es sedan o coupé.
 */
void Estacion3::worker()
{
    while (true)
    {
        auto carro = std::move(cadena_traslado_2a3->obtener_carro_actual());
        if (carro == nullptr)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }

        double intervalo_procesamiento = tiempo_procesamiento(generador);

        std::cerr << "Llego a la Estacion 3 el carro con ID: " << carro->get_id() << '\n';
        std::cerr << "Tiempo de procesamiento Estacion 3 carro con ID " << carro->get_id() << ": " << intervalo_procesamiento << '\n';

        std::this_thread::sleep_for(std::chrono::seconds(int(intervalo_procesamiento) + 1));

        carro->set_motor_model(generador() % 4); // Se escoge entre motores desde 1.4 a 2.0

        std::cerr << "Saliendo de la Estacion 3 el carro con ID:" << carro->get_id() << '\n';

        cadena_traslado_3a4->insertar_log("Completado correctamente Estacion3 carro con ID: " + carro->get_id());
        cadena_traslado_3a4->insertar_carro(std::move(carro));
    }
}