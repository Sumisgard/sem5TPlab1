#pragma once

#include <string>
#include <iostream>
#include <fstream>

namespace utils
{
    class Garage
    {
    public:
        Garage();
        ~Garage();
        unsigned int get_carCount();
        unsigned int get_motorcycleCount();
        unsigned int get_busCount();
        Garage& operator=(const Garage& obj);
        void addCar(std::string brand, std::string model, unsigned int liters, std::string color, std::string type);
        void addMotorcycle(std::string brand, std::string model, unsigned int liters,  unsigned int power, std::string terrain);
        void addBus(std::string brand, std::string model, unsigned int passengerSeats, unsigned int totalSeats, std::string destination);
        void deleteCar(unsigned int index);
        void deleteMotorcycle(unsigned int index);
        void deleteBus(unsigned int index);
        void listVehiclesInGarage();
        void saveToFile(std::string filename);
        static Garage loadFromFile(std::string filename);
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
            Vehicle();
            Vehicle(std::string brand, std::string model);
            virtual void sayHi() = 0;
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
            Car();
            Car(Car &car);
            Car(std::string brand, std::string model, unsigned int liters, std::string color, std::string type);
            void sayHi() override;
            void set_engineVolume(unsigned int liters);
            void set_color(std::string color);
            void set_checkpointType(std::string type);
            void set_carData(std::string brand, std::string model, unsigned int liters, std::string color, std::string type);
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
            Motorcycle();
            Motorcycle(Motorcycle &motorcycle);
            Motorcycle(std::string brand, std::string model, unsigned int liters, unsigned int power, std::string terrain);
            void sayHi() override;
            void set_engineVolume(unsigned int liters);
            void set_horsepower(unsigned int power);
            void set_preferredTerrain(std::string terrain);
            void set_motorcycleData(std::string brand, std::string model, unsigned int liters,  unsigned int power, std::string terrain);
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
            Bus();
            Bus(Bus &bus);
            Bus(std::string brand, std::string model, unsigned int passengerSeats, unsigned int totalSeats, std::string destination);
            void sayHi() override;
            void set_passengerSeats(unsigned int seats);
            void set_totalSeats(unsigned int seats);
            void set_destination(std::string destination);
            void set_busData(std::string brand, std::string model, unsigned int passengerSeats, unsigned int totalSeats, std::string destination);
            unsigned int get_passengerSeats();
            unsigned int get_totalSeats();
            std::string get_destination();
        };

        Car* cars;
        Motorcycle* motorcycles;
        Bus* buses;

    };
}