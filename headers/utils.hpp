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
            void set_brand(std::string brand);
            void set_model(std::string model)
            {
                this->model = model;
            }
            std::string get_brand()
            {
                return this->brand;
            }
            std::string get_model()
            {
                return this->model;
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
            unsigned int get_engineVolume()
            {
                return this->engineVolume;
            }
            std::string get_color()
            {
                return this->color;
            }
            std::string get_checkpointType()
            {
                return this->checkpointType;
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
            unsigned int get_engineVolume()
            {
                return this->engineVolume;
            }
            unsigned int get_horsepower()
            {
                return this->horsepower;
            }
            std::string get_preferredTerrain()
            {
                return this->preferredTerrain;
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
            unsigned int get_passengerSeats()
            {
                return this->passengerSeats;
            }
            unsigned int get_totalSeats()
            {
                return this->totalSeats;
            }
            std::string get_destination()
            {
                return this->destination;
            }
        };

        Car* cars;
        Motorcycle* motorcycles;
        Bus* buses;

    public:

    };
}