#ifndef __CARRO_HEADER__
#define __CARRO_HEADER__

#include <mutex>

const std::string color[11] = { "Negro", "Azul", "Marron", "Gris", 
    "Verde", "Naranja", "Rosa", "Purpura", "Rojo", "Blanco", "Amarrillo" };

const std::string car_model[2] = { "Coupe", "Sedan" };

const std::string seats_model[2] = { "Tela", "Cuero" };

const std::string motor_model[4] = { "1.4", "1.6", "1.8", "2.0" };

class Carro
{
private:
    long long id;
    int volume;
    int num_doors;
    int color;
    int car_model;
    int motor_model;
    int seats_model;
    std::mutex mux;

public:
    Carro() = default;
    Carro(const Carro &) = delete;
    ~Carro() = default;

    void set_id(long long);
    void set_volume(int);
    void set_num_doors(int);
    void set_color(int);
    void set_car_model(int);
    void set_motor_model(int);
    void set_seats_model(int);

    long long get_id();
    int get_volume();
    int get_num_doors();
    int get_color();
    int get_car_model();
    int get_motor_model();
    int get_seats_model();
};

#endif //__CARRO_HEADER__
