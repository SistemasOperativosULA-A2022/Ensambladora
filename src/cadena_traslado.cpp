#include <cadena_traslado.hpp>

void CadenaDeTraslado::insertar_carro(std::unique_ptr<Carro> carro)
{
    this->mux.lock();
    this->cadena_traslado.push(std::move(carro));
    this->mux.unlock();
}

std::unique_ptr<Carro> CadenaDeTraslado::obtener_carro_actual()
{
    std::unique_ptr<Carro> value = nullptr;
    if (not this->cadena_traslado.empty())
    {
        this->mux.lock();
        value = std::move(this->cadena_traslado.front());
        this->cadena_traslado.pop();
        this->mux.unlock();
    }

    return value;
}

void CadenaDeTraslado::insertar_log(std::string cadena)
{
    this->logs_mux.lock();
    this->logs.push(cadena);
    this->logs_mux.unlock();
}

std::string CadenaDeTraslado::obtener_log()
{
    std::string value = "";
    if (not this->logs.empty())
    {
        this->mux.lock();
        value = this->logs.front();
        this->logs.pop();
        this->mux.unlock();
    }

    return value;
}