#include <iostream>
#include "utils.hpp"

using namespace utils;

int main(void)
{
    Garage container;

    container.addCar("BMW", "X5", 5, "gay blue", "In");
    container.addCar("Audi", "Q5", 5, "lesbian pink", "Out");

    container.addMotorcycle("Yamaha", "");

    return 0;
}
