#pragma once

#include <string>

namespace utils
{
    class Garage
    {
    private:
        class Vehicle
        {
        private:
            std::string brand;
            std::string model;
        public:
            void set_brand(std::string brand)
            {
                this->brand = brand;
            }
            void set_model(std::string brand)
            {
                this->brand = brand;
            }
        };

        class Car: public Vehicle
        {
        private:
            unsigned int engineVolume;
            std::string color;
            std::string checkpointType;
        public:
            void set_engineVolume(unsigned int liters)
            {
                this->engineVolume = liters;
            }
            void set_color(std::string color)
            {
                this->color = color;
            }
            void set_checkpointType(std::string type)
            {
                this->checkpointType = type;
            }
        };

        class Motorcycle: public Vehicle
        {
        private:
            unsigned int engineVolume;
            unsigned int horsepower;
            std::string preferredTerrain;
        public:
            void set_engineVolume(unsigned int liters)
            {
                this->engineVolume = liters;
            }
            void set_horsepower(unsigned int power)
            {
                this->horsepower = power;
            }
            void set_preferredTerrain(std::string terrain)
            {
                this->preferredTerrain = terrain;
            }
        };

        class Bus: public Vehicle
        {
        private:
            unsigned int passengerSeats;
            unsigned int totalSeats;
            std::string destination;
        public:
            void set_passengerSeats(unsigned int seats)
            {
                this->passengerSeats = seats;
            }
            void set_totalSeats(unsigned int seats)
            {
                this->totalSeats = seats;
            }
            void set_destination(std::string destination)
            {
                this->destination = destination;
            }           
        };

        Car* cars;
        Motorcycle* motorcycles;
        Bus* buses;

    public:

    };
}