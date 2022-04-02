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
    std::shared_ptr<Carro> c) : generador(seed), 
                                tiempo_procesamiento(M4, D4),
                                carro(c)
                                                            
{
    // empty
}

/**
 * @brief Proceso que duerme el intervalo de segundo obtenido a través de 
 * la distriubción normal (tiempo de procesamiento), se procede a la colocacion
 * de los asientos del carro. 
 */
void Estacion4::ejecutar()
{
    double intervalo_procesamiento = tiempo_procesamiento(generador);
    
    std::cerr << "Llego a la Estacion 4 el carro con ID: " << carro->get_id() << '\n';
    std::cerr << "Tiempo de procesamiento: " << intervalo_procesamiento << '\n';
    
    std::this_thread::sleep_for(std::chrono::seconds(int(intervalo_procesamiento) + 1));
    
    carro->set_seats_model(generador()%2); // 0 son asientos de tela, 1 son asientos de cuero
}
