/**
 * @file cadena_traslado.hpp
 * @author Jorge Luis Rodríguez González (egroj97@gmail.com)
 * @version 0.1
 * @date 2022-04-02
 */

#ifndef __CARRO_HEADER__
#define __CARRO_HEADER__

#include <mutex>

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