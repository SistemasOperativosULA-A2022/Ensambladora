/**
 * @file cadena_traslado.hpp
 * @author Jorge Luis Rodríguez González (egroj97@gmail.com)
 * @version 0.1
 * @date 2022-04-02
 */

#ifndef __CADENA_DE_TRASLADO_HEADER__
#define __CADENA_DE_TRASLADO_HEADER__

#include <queue>
#include <mutex>
#include <memory>
#include <carro.hpp>

class CadenaDeTraslado
{
private:
    std::queue<std::unique_ptr<Carro>> cadena_traslado;
    std::mutex mux;
    std::queue<std::string> logs;
    std::mutex logs_mux;

public:
    CadenaDeTraslado() = default;
    ~CadenaDeTraslado() = default;

    void insertar_carro(std::unique_ptr<Carro>);
    std::unique_ptr<Carro> obtener_carro_actual();
    void insertar_log(std::string);
    std::string obtener_log();
};

#endif // __CADENA_DE_TRASLADO_HEADER__