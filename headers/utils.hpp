#pragma once

#include <string>

namespace utils
{
    class Garage
    {
    public:
        Garage();
        void addCar();
        void addMotorcycle();
        void addBus();
    private:
        unsigned int carCount;
        unsigned int motorcycleCount;
        unsigned int busCount;
        class Vehicle
        {
        private:
            std::string brand;
            std::string model;
        public:
            Vehicle(std::string brand, std::string model);
            void set_brand(std::string brand);
            void set_model(std::string model);
            std::string get_brand();
            std::string get_model();
        };

        class Car: public Vehicle
        {
        private:
            unsigned int engineVolume;
            std::string color;
            std::string checkpointType;
        public:
            Car(std::string brand, std::string model, unsigned int liters, std::string color, std::string type);
            void set_engineVolume(unsigned int liters);
            void set_color(std::string color);
            void set_checkpointType(std::string type);
            unsigned int get_engineVolume();
            std::string get_color();
            std::string get_checkpointType();
        };

        class Motorcycle: public Vehicle
        {
        private:
            unsigned int engineVolume;
            unsigned int horsepower;
            std::string preferredTerrain;
        public:
            Motorcycle(std::string brand, std::string model, unsigned int liters, unsigned int power, std::string terrain);
            void set_engineVolume(unsigned int liters);
            void set_horsepower(unsigned int power);
            void set_preferredTerrain(std::string terrain);
            unsigned int get_engineVolume();
            unsigned int get_horsepower();
            std::string get_preferredTerrain();
        };

        class Bus: public Vehicle
        {
        private:
            unsigned int passengerSeats;
            unsigned int totalSeats;
            std::string destination;
        public:
            Bus(std::string brand, std::string model, unsigned int passengerSeats, unsigned int totalSeats, std::string destination);
            void set_passengerSeats(unsigned int seats);
            void set_totalSeats(unsigned int seats);
            void set_destination(std::string destination);      
            unsigned int get_passengerSeats();
            unsigned int get_totalSeats();
            std::string get_destination();
        };

        Car* cars;
        Motorcycle* motorcycles;
        Bus* buses;

    };
}