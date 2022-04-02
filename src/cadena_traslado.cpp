#include <cadena_traslado.hpp>

CadenaDeTraslado::CadenaDeTraslado()
{
}

CadenaDeTraslado::~CadenaDeTraslado()
{
}

void CadenaDeTraslado::insertar_carro(std::unique_ptr<Carro> carro)
{
    this->mux.lock();
    this->cadena_traslado.push(std::move(carro));
    this->mux.unlock();
}

std::unique_ptr<Carro> CadenaDeTraslado::obtener_carro_actual()
{
    std::unique_ptr<Carro> value;
    this->mux.lock();
    value = std::move(this->cadena_traslado.front());
    this->cadena_traslado.pop();
    this->mux.unlock();

    return value;
}