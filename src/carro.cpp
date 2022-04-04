#include <carro.hpp>

void Carro::set_id(long long id)
{
    this->mux.lock();
    this->id = id;
    this->mux.unlock();
}

void Carro::set_volume(int volume)
{
    this->mux.lock();
    this->volume = volume;
    this->mux.unlock();
}

void Carro::set_num_doors(int num_doors)
{
    this->mux.lock();
    this->num_doors = num_doors;
    this->mux.unlock();
}

void Carro::set_color(int color)
{
    this->mux.lock();
    this->color = color;
    this->mux.unlock();
}

void Carro::set_car_model(int car_model)
{
    this->mux.lock();
    this->car_model = car_model;
    this->mux.unlock();
}

void Carro::set_motor_model(int motor_model)
{
    this->mux.lock();
    this->motor_model = motor_model;
    this->mux.unlock();
}

void Carro::set_seats_model(int seats_model)
{
    this->mux.lock();
    this->seats_model = seats_model;
    this->mux.unlock();
}

long long Carro::get_id()
{
    return this->id;
}

int Carro::get_volume()
{
    return this->volume;
}

int Carro::get_num_doors()
{
    return this->num_doors;
}

int Carro::get_color()
{
    return this->color;
}

int Carro::get_car_model()
{
    return this->car_model;
}

int Carro::get_motor_model()
{
    return this->motor_model;
}

int Carro::get_seats_model()
{
    return this->seats_model;
}