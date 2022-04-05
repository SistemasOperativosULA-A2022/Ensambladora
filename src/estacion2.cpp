#include <estacion2.hpp>

#include <iostream>

/**
 * @brief Construye una nueva Estacion 2
 *
 * @param seed Semilla para el generador de numeros aleatorio
 * @param M2 Media 2
 * @param D2 Desviación Estandar 2
 * @param carro Carro recibido desde la estacion 1
 */
Estacion2::Estacion2(
    unsigned seed,
    double M2,
    double D2,
    std::shared_ptr<CadenaDeTraslado> c1a2,
    std::shared_ptr<CadenaDeTraslado> c2a3) : generador(seed),
                                              tiempo_procesamiento(M2, D2),
                                              cadena_traslado_1a2(c1a2),
                                              cadena_traslado_2a3(c2a3),
                                              prev_color(-1)

{
    // empty
}

/**
 * @brief Hilo infinito que duerme el intervalo de segundo obtenido a través de
 * la distriubción normal (tiempo de procesamiento), se procede a pintar
 * los carros llegados de la estacion 2.
 */
void Estacion2::ejecutar()
{
    while (true)
    {
        auto carro = std::move(cadena_traslado_1a2->obtener_carro_actual());
        if (carro == nullptr)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }

        double intervalo_procesamiento = tiempo_procesamiento(generador);

        std::cerr << "Llegó a la Estación2 carro ID = " << carro->get_id() << " . Asignando color y modelo en t = " << intervalo_procesamiento << std::endl;
        
        std::this_thread::sleep_for(std::chrono::seconds(int(intervalo_procesamiento) + 1));

        carro->set_car_model(generador() % 2); // 0 es coupe, 1 es sedan
        while (prev_color == carro->get_color())
        {
            carro->set_color(generador() % 11); // del 0 a 11 son los posibles colores que puede tener el carro
        }

        prev_color = carro->get_color();

        std::cerr << "Saliendo de la Estacion2 el carro con ID: " << carro->get_id() << '\n';

        cadena_traslado_2a3->insertar_log("\nCompletado correctamente Estación2 carro con ID: " + carro->get_id());
        cadena_traslado_2a3->insertar_carro(std::move(carro));
    }
}
