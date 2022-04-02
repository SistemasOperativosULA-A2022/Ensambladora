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

public:
    CadenaDeTraslado();
    ~CadenaDeTraslado();

    void insertar_carro(std::unique_ptr<Carro>);
    std::unique_ptr<Carro> obtener_carro_actual();
};

#endif // __CADENA_DE_TRASLADO_HEADER__