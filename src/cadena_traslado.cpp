#include <cadena_traslado.hpp>

void CadenaDeTraslado::insertar_carro(std::unique_ptr<Carro> carro)
{
    this->mux.lock();
    this->cadena_traslado.push(std::move(carro));
    this->produccion++;
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

void CadenaDeTraslado::conexion_cadena(std::string cadena, int var)
{
    this->cadena[var].append(cadena);
}

std::string CadenaDeTraslado::mostrar_cadena(int var)
{
    return this->cadena[var].data();
}

unsigned long long CadenaDeTraslado::get_produccion()
{
    return this->produccion;
}