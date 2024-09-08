#pragma once

#include <string>

namespace utils
{
    class Garage
    {
    private:
        class Vehicle
        {
        protected:
            std::string brand;
            std::string model;
        public:
            void set_brand(std::string brand)
            {
                this->brand = brand;
            }
        };

        class Car
        {

        };

        class Motorcycle
        {

        };

        class Bus
        {

        };

        Car* cars;
        Motorcycle* motorcycles;
        Bus* buses;

    public:

    };
}