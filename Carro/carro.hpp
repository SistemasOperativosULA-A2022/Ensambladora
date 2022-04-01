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
    Carro(long long id);
    ~Carro();
};
