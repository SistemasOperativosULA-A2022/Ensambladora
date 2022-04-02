#ifndef __CADENA_DE_TRASLADO_HEADER__
#define __CADENA_DE_TRASLADO_HEADER__

#include <queue>
#include <mutex>
#include <memory>
#include <Carro/carro.hpp>

class CadenaDeTraslado1A2
{
private:
    std::queue<std::unique_ptr<Carro>> cadena_traslado;
    std::mutex mux;

public:
    CadenaDeTraslado1A2();
    ~CadenaDeTraslado1A2();

    void insertar_carro(std::unique_ptr<Carro>);
    std::unique_ptr<Carro> obtener_carro_actual();
};

#endif // __CADENA_DE_TRASLADO_HEADER__