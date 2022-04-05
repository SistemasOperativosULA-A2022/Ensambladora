#include <estacion4.hpp>

#include <iostream>

/**
 * @brief Construye una nueva Estacion 4
 *
 * @param seed Semilla para el generador de numeros aleatorio
 * @param M4 Media 4
 * @param D4 Desviación Estandar 4
 * @param c3a4 Cadena de traslado desde la estacion 3 a la estacion 4
 * @param cf Cadena final de traslado
 */
Estacion4::Estacion4(
    double seed,
    double M4,
    double D4,
    std::shared_ptr<CadenaDeTraslado> c3a4,
    std::shared_ptr<CadenaDeTraslado> cf) : generador(seed),
                                            tiempo_procesamiento(M4, D4),
                                            cadena_traslado3a4(c3a4),
                                            cadena_traslado_final(cf)

{
    // empty
}

/**
 * @brief Hilo infinito que duerme el intervalo de segundo obtenido a través de
 * la distriubción normal (tiempo de procesamiento), se procede a la colocacion
 * de los asientos de los carros llegados de la estacion 3.
 */
void Estacion4::ejecutar()
{
    while (true)
    {
        auto carro = std::move(cadena_traslado3a4->obtener_carro_actual());
        if (carro == nullptr)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }

        double intervalo_procesamiento = tiempo_procesamiento(generador);

        std::cerr << "Llegó a la Estación4 carro ID = " << carro->get_id() << " . Asignando asientos en t = " << intervalo_procesamiento << std::endl;
        
        std::this_thread::sleep_for(std::chrono::seconds(int(intervalo_procesamiento) + 1));

        carro->set_seats_model(generador() % 2); // 0 son asientos de tela, 1 son asientos de cuero

        this->cadena_traslado_final->insertar_log("Completado correctamente Estación4 carro con ID: " + carro->get_id());

        std::cerr << "Saliendo de la Estación4 el carro con ID: " << carro->get_id() << '\n';

        cadena_traslado_final->insertar_carro(std::move(carro));
    }
}
