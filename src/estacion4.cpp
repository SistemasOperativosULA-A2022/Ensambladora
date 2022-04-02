#include <estacion4.hpp>

#include <iostream>

/**
 * @brief Construye una nueva Estacion 4
 *
 * @param seed Semilla para el generador de numeros aleatorio
 * @param M4 Media 4
 * @param D4 Desviación Estandar 4 
 * @param carro Carro recibido desde la estacion 3
 */
Estacion4::Estacion4(
    double seed, 
    double M4, 
    double D4, 
    std::shared_ptr<CadenaDeTraslado> c) :  generador(seed), 
                                            tiempo_procesamiento(M4, D4),
                                            cadena_traslado(c)
                                                            
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
        auto carro = std::move(cadena_traslado->obtener_carro_actual());
        
        if (carro != nullptr)
        {
            double intervalo_procesamiento = tiempo_procesamiento(generador);
    
            std::cerr << "Llego a la Estacion 4 el carro con ID: " << carro->get_id() << '\n';
            std::cerr << "Tiempo de procesamiento Estacion 4 carro con ID " << carro->get_id() << ": " << intervalo_procesamiento << '\n';
            
            std::this_thread::sleep_for(std::chrono::seconds(int(intervalo_procesamiento) + 1));
            
            carro->set_seats_model(generador()%2); // 0 son asientos de tela, 1 son asientos de cuero
            
            std::cerr << "Saliendo de la Estacion 4 el carro con ID:" << carro->get_id() << '\n';
            std::cerr << "Color=: " << carro->get_color() << '\n';
            std::cerr << "Modelo= " << carro->get_car_model() << '\n';
            std::cerr << "Motor=: " << carro->get_motor_model() << '\n';
            std::cerr << "Asientos= " << seats_model[carro->get_seats_model()]<< '\n';
            
            
        }
    }
}
