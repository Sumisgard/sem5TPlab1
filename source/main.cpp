#include <iostream>
#include "utils.hpp"
 
using namespace utils;

int main(void)
{
    bool state = 1;
    int choise = 0;
    std::string choise1 = "";

    std::string cbrand = "";
    std::string cmodel = "";
    std::string cproperty1 = "";
    std::string cproperty2 = "";
    std::string cproperty3 = "";
    std::string cindex = "";
    std::string cfilename = "";

    Garage container;

    while (state == 1)
    {   
        std::cout << "In Garage:\n"; 
        container.listVehiclesInGarage();
        std::cout << "Choose an option:\n"
                  << "\t1. Add Car\n"
                  << "\t2. Add Motorcycle\n"
                  << "\t3. Add Bus\n"
                  << "\t4. Delete Car\n"
                  << "\t5. Delete Motorcycle\n"
                  << "\t6. Delete Bus\n"
                  << "\t7. Save to file\n"
                  << "\t8. Load from file\n"
                  << "\t9. Exit\n";
        std::cin >> choise1;
        choise = stoi(choise1);
        switch (choise)
        {
        case 1:
            std::cout << "Type Car brand:\n";
            std::cin >> cbrand;
            std::cout << "Type Car model:\n";
            std::cin >> cmodel;
            std::cout << "Type engine volume:\n";
            std::cin >> cproperty1;
            std::cout << "Type Car color:\n"; 
            std::cin >> cproperty2;
            std::cout << "Type Checkpoint type:\n";
            std::cin >> cproperty3;

            container.addCar(cbrand, cmodel, stoi(cproperty1), cproperty2, cproperty3);
            break;
        case 2:
            std::cout << "Type Motorcycle brand:\n";
            std::cin >> cbrand;
            std::cout << "Type Motorcycle model:\n";
            std::cin >> cmodel;
            std::cout << "Type engine volume:\n";
            std::cin >> cproperty1;
            std::cout << "Type Motorcycle horsepower:\n"; 
            std::cin >> cproperty2;
            std::cout << "Type terrain type:\n";
            std::cin >> cproperty3;

            container.addMotorcycle(cbrand, cmodel, stoi(cproperty1), stoi(cproperty2), cproperty3);
            break;
        case 3:
            std::cout << "Type Bus brand:\n";
            std::cin >> cbrand;
            std::cout << "Type Bus model:\n";
            std::cin >> cmodel;
            std::cout << "Type passenger seats:\n";
            std::cin >> cproperty1;
            std::cout << "Type total seats:\n"; 
            std::cin >> cproperty2;
            std::cout << "Type destination:\n";
            std::cin >> cproperty3;

            container.addBus(cbrand, cmodel, stoi(cproperty1), stoi(cproperty2), cproperty3);
            break;
        case 4:
            std::cout << "Type car index to delete:\n";
            std::cin >> cindex;
            container.deleteCar(stoi(cindex));
            break;
        case 5:
            std::cout << "Type motorcycle index to delete:\n";
            std::cin >> cindex;
            container.deleteMotorcycle(stoi(cindex));
            break;
        case 6:
            std::cout << "Type bus index to delete:\n";
            std::cin >> cindex;
            container.deleteBus(stoi(cindex));
            break;
        case 7:
            std::cout << "Type filename:\n";
            std::cin >> cfilename;
            container.saveToFile(cfilename);
            break;
        case 8:
            std::cout << "Type filename:\n";
            std::cin >> cfilename;
            container = Garage::loadFromFile(cfilename);
            break;
        case 9:
            state = 0;
            break;
        default:
            break;
        }
    }

#ifdef TEST

    container.addCar("BMW", "X5", 5, "gayblue", "In");
    container.addCar("Audi", "Q5", 5, "les&bianpink", "Out");

    container.addMotorcycle("Yamaha", "R1", 5, 200, "Offroad");
    container.addMotorcycle("Yamaha", "R2", 6, 250, "Offroad");
    container.addMotorcycle("Yamaha", "K1", 3, 150, "Road");

    container.addBus("Volgabus", "Sovet", 20, 22, "Hell");
    container.addBus("Oksana", "Love", 24, 27, "Home");
    container.addBus("Oksana", "Hate", 10, 12, "Heaven");
    container.addBus("Volgabus", "Narod", 30, 32, "Hello");

    container.listVehiclesInGarage();

    container.deleteCar(0);
    container.deleteBus(0);
    container.deleteMotorcycle(1);
    
    container.listVehiclesInGarage();


    Garage container2 = Garage::loadFromFile("savefile.txt");
    container2.listVehiclesInGarage();

#endif

    return 0;
}
