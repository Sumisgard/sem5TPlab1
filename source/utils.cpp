#include "utils.hpp"

namespace utils
{
    Garage::Garage()
    {
        this->carCount = 0;
        this->motorcycleCount = 0;
        this->busCount = 0;
        
        this->cars = nullptr;
        this->motorcycles = nullptr;
        this->buses = nullptr;
    }
    unsigned int Garage::get_carCount()
    {
        return this->carCount;
    }
    unsigned int Garage::get_motorcycleCount()
    {
        return this->motorcycleCount;
    }
    unsigned int Garage::get_busCount()
    {
        return this->busCount;
    }
    void Garage::addCar(std::string brand, std::string model, unsigned int liters, std::string color, std::string type)
    {
        if (this->carCount == 0)
        {
            ++(this->carCount);
            this->cars = new Car(brand, model, liters, color, type);
        }
        else if (this->carCount == 1)
        {
            ++(this->carCount);
            Car* newCars = new Car[carCount];
        }
    }
    Garage::Vehicle::Vehicle(std::string brand, std::string model)
    {
        this->brand = brand;
        this->model = model;
    }
    void Garage::Vehicle::set_brand(std::string brand)
    {
        this->brand = brand;
    }
    void Garage::Vehicle::set_model(std::string model)
    {
        this->model = model;
    }
    std::string Garage::Vehicle::get_brand()
    {
        return this->brand;
    }
    std::string Garage::Vehicle::get_model()
    {
        return this->model;
    }
    Garage::Car::Car()
    {
        this->engineVolume = 0;
        this->color = "";
        this->checkpointType = "";
    }
    Garage::Car::Car(std::string brand, std::string model, unsigned int liters, std::string color, std::string type): Vehicle(brand, model)
    {
        this->engineVolume = liters;
        this->color = color;
        this->checkpointType = type;
    }
    void Garage::Car::set_engineVolume(unsigned int liters)
    {
        this->engineVolume = liters;
    }
    void Garage::Car::set_color(std::string color)
    {
        this->color = color;
    }
    void Garage::Car::set_checkpointType(std::string type)
    {
        this->checkpointType = type;
    }
    unsigned int Garage::Car::get_engineVolume()
    {
        return this->engineVolume;
    }
    std::string Garage::Car::get_color()
    {
        return this->color;
    }
    std::string Garage::Car::get_checkpointType()
    {
        return this->checkpointType;
    }
    Garage::Motorcycle::Motorcycle(std::string brand, std::string model, unsigned int liters, unsigned int power, std::string terrain): Vehicle(brand, model)
    {
        this->engineVolume = liters;
        this->horsepower = power;
        this->preferredTerrain = terrain;
    }
    void Garage::Motorcycle::set_engineVolume(unsigned int liters)
    {
        this->engineVolume = liters;
    }
    void Garage::Motorcycle::set_horsepower(unsigned int power)
    {
        this->horsepower = power;
    }
    void Garage::Motorcycle::set_preferredTerrain(std::string terrain)
    {
        this->preferredTerrain = terrain;
    }
    unsigned int Garage::Motorcycle::get_engineVolume()
    {
        return this->engineVolume;
    }
    unsigned int Garage::Motorcycle::get_horsepower()
    {
        return this->horsepower;
    }
    std::string Garage::Motorcycle::get_preferredTerrain()
    {
        return this->preferredTerrain;
    }
    Garage::Bus::Bus(std::string brand, std::string model, unsigned int passengerSeats, unsigned int totalSeats, std::string destination): Vehicle(brand, model)
    {
        this->passengerSeats = passengerSeats;
        this->totalSeats = totalSeats;
        this->destination = destination;
    }
    void Garage::Bus::set_passengerSeats(unsigned int seats)
    {
        this->passengerSeats = seats;
    }
    void Garage::Bus::set_totalSeats(unsigned int seats)
    {
        this->totalSeats = seats;
    }
    void Garage::Bus::set_destination(std::string destination)
    {
        this->destination = destination;
    }           
    unsigned int Garage::Bus::get_passengerSeats()
    {
        return this->passengerSeats;
    }
    unsigned int Garage::Bus::get_totalSeats()
    {
        return this->totalSeats;
    }
    std::string Garage::Bus::get_destination()
    {
        return this->destination;
    }
}