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
    Garage::~Garage()
    {
        for (int i = carCount - 1; i >= 0; --i)
        {
            this->deleteCar(i);
        }
        for (int i = motorcycleCount - 1; i >= 0; --i)
        {
            this->deleteMotorcycle(i);
        }
        for (int i = busCount - 1; i >= 0; --i)
        {
            this->deleteBus(i);
        }
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
    Garage& Garage::operator=(const Garage& obj)
    {
        this->carCount = obj.carCount;
        this->busCount = obj.busCount;
        this->motorcycleCount = obj.motorcycleCount;
        if (obj.carCount != 1)
        {
            this->cars = new Car[obj.carCount];
            for (int i = 0; i < obj.carCount; ++i)
            {
                cars[i].set_carData(obj.cars[i].get_brand(), obj.cars[i].get_model(), obj.cars[i].get_engineVolume(), obj.cars[i].get_color(), obj.cars[i].get_checkpointType());
            }
        }
        else
        {
            this->cars = new Car(obj.cars->get_brand(), obj.cars->get_model(), obj.cars->get_engineVolume(), obj.cars->get_color(), obj.cars->get_checkpointType());
        }
        
        if (obj.motorcycleCount != 1)
        {
            this->motorcycles = new Motorcycle[obj.motorcycleCount];
            for (int i = 0; i < obj.motorcycleCount; ++i)
            {
                motorcycles[i].set_motorcycleData(obj.motorcycles[i].get_brand(), obj.motorcycles[i].get_model(), obj.motorcycles[i].get_engineVolume(), obj.motorcycles[i].get_horsepower(), obj.motorcycles[i].get_preferredTerrain());
            }
        }
        else
        {
            this->motorcycles = new Motorcycle(obj.motorcycles->get_brand(), obj.motorcycles->get_model(), obj.motorcycles->get_engineVolume(), obj.motorcycles->get_horsepower(), obj.motorcycles->get_preferredTerrain());
        }

        if (obj.busCount != 1)
        {
            this->buses = new Bus[obj.busCount];
            for (int i = 0; i < obj.busCount; ++i)
            {
                buses[i].set_busData(obj.buses[i].get_brand(), obj.buses[i].get_model(), obj.buses[i].get_passengerSeats(), obj.buses[i].get_totalSeats(), obj.buses[i].get_destination());
            }
        }
        else
        {
            this->buses = new Bus(obj.buses->get_brand(), obj.buses->get_model(), obj.buses->get_passengerSeats(), obj.buses->get_totalSeats(), obj.buses->get_destination());
        }

        return *this;
    }
    void Garage::addCar(std::string brand, std::string model, unsigned int liters, std::string color, std::string type)
    {
        if (this->carCount == 0)
        {
            ++(this->carCount);
            this->cars = new Car(brand, model, liters, color, type);
        }
        // Exessive
        // else if (this->carCount == 1)
        // {
        //     ++(this->carCount);
        //     Car* newCars = new Car[carCount];
        //     newCars[0].set_carData(this->cars->get_brand(), this->cars->get_model(), this->cars->get_engineVolume(), this->cars->get_color(), this->cars->get_checkpointType());
        //     newCars[1].set_carData(brand, model, liters, color, type);
        //     delete this->cars;
        //     this->cars = newCars;
        // }
        else
        {
            ++(this->carCount);
            Car* newCars = new Car[carCount];
            for (int i = 0; i < carCount - 1; ++i)
            {
                newCars[i].set_carData(this->cars[i].get_brand(), this->cars[i].get_model(), this->cars[i].get_engineVolume(), this->cars[i].get_color(), this->cars[i].get_checkpointType());
            }
            newCars[carCount - 1].set_carData(brand, model, liters, color, type);
            if (this->carCount == 2)
                delete this->cars;
            else
                delete[] this->cars;
            this->cars = newCars;
        }
    }
    void Garage::addMotorcycle(std::string brand, std::string model, unsigned int liters,  unsigned int power, std::string terrain)
    {
        if (this->motorcycleCount == 0)
        {
            ++(this->motorcycleCount);
            this->motorcycles = new Motorcycle(brand, model, liters, power, terrain);
        }
        else
        {
            ++(this->motorcycleCount);
            Motorcycle* newMotorcycles = new Motorcycle[motorcycleCount];
            for (int i = 0; i < motorcycleCount - 1; ++i)
            {
                newMotorcycles[i].set_motorcycleData(this->motorcycles[i].get_brand(), this->motorcycles[i].get_model(), this->motorcycles[i].get_engineVolume(), this->motorcycles[i].get_horsepower(), this->motorcycles[i].get_preferredTerrain());
            }
            newMotorcycles[motorcycleCount - 1].set_motorcycleData(brand, model, liters, power, terrain);
            if (this->motorcycleCount == 2)
                delete this->motorcycles;
            else
                delete[] this->motorcycles;
            this->motorcycles = newMotorcycles;
        }
    }
    void Garage::addBus(std::string brand, std::string model, unsigned int passengerSeats, unsigned int totalSeats, std::string destination)
    {
        if (this->busCount == 0)
        {
            ++(this->busCount);
            this->buses = new Bus(brand, model, passengerSeats, totalSeats, destination);
        }
        else
        {
            ++(this->busCount);
            Bus* newBuses = new Bus[busCount];
            for (int i = 0; i < busCount - 1; ++i)
            {
                newBuses[i].set_busData(this->buses[i].get_brand(), this->buses[i].get_model(), this->buses[i].get_passengerSeats(), this->buses[i].get_totalSeats(), this->buses[i].get_destination());
            }
            newBuses[busCount - 1].set_busData(brand, model, passengerSeats, totalSeats, destination);
            if (this->busCount == 2)
                delete this->buses;
            else
                delete[] this->buses;
            this->buses = newBuses;
        }
    }
    void Garage::deleteCar(unsigned int index)
    {
        if (carCount == 1)
        {
            --(this->carCount);
            delete this->cars;
        }
        else
        {
            int j = 0;
            if (this->carCount == 2)
            {
                Car* newCars = new Car();
                if (index == 1)
                    newCars->set_carData(this->cars[0].get_brand(), this->cars[0].get_model(), this->cars[0].get_engineVolume(), this->cars[0].get_color(), this->cars[0].get_checkpointType());
                else
                    newCars->set_carData(this->cars[1].get_brand(), this->cars[1].get_model(), this->cars[1].get_engineVolume(), this->cars[1].get_color(), this->cars[1].get_checkpointType());
                delete[] this->cars;
                this->cars = newCars;
                --(this->carCount);
            }
            else
            {
                Car* newCars = new Car[carCount - 1];
                for (int i = 0; i < carCount; ++i)
                {
                    if (i != index)
                    {
                        newCars[j] = this->cars[i];
                        ++j;
                    }
                    else
                    {
                        continue;
                    }
                }
                delete[] this->cars;
                this->cars = newCars;
                --(this->carCount);
            }
        }
    }
    void Garage::deleteMotorcycle(unsigned int index)
    {
        if (motorcycleCount == 1)
        {
            --(this->motorcycleCount);
            delete this->motorcycles;
        }
        else
        {
            int j = 0;
            if (this->motorcycleCount == 2)
            {
                Motorcycle* newMotorcycles = new Motorcycle();
                if (index == 1)
                    newMotorcycles->set_motorcycleData(this->motorcycles[0].get_brand(), this->motorcycles[0].get_model(), this->motorcycles[0].get_engineVolume(), this->motorcycles[0].get_horsepower(), this->motorcycles[0].get_preferredTerrain());
                else
                    newMotorcycles->set_motorcycleData(this->motorcycles[1].get_brand(), this->motorcycles[1].get_model(), this->motorcycles[1].get_engineVolume(), this->motorcycles[1].get_horsepower(), this->motorcycles[1].get_preferredTerrain());
                delete[] this->motorcycles;
                this->motorcycles = newMotorcycles;
                --(this->motorcycleCount);
            }
            else
            {
                Motorcycle* newMotorcycles = new Motorcycle[motorcycleCount - 1];
                for (int i = 0; i < motorcycleCount; ++i)
                {
                    if (i != index)
                    {
                        newMotorcycles[j] = this->motorcycles[i];
                        ++j;
                    }
                    else
                    {
                        continue;
                    }
                }
                delete[] this->motorcycles;
                this->motorcycles = newMotorcycles;
                --(this->motorcycleCount);
            }
        }
    }
    void Garage::deleteBus(unsigned int index)
    {
        if (busCount == 1)
        {
            --(this->busCount);
            delete this->buses;
        }
        else
        {
            int j = 0;
            if (this->busCount == 2)
            {
                Bus* newBuses = new Bus();
                if (index == 1)
                    newBuses->set_busData(this->buses[0].get_brand(), this->buses[0].get_model(), this->buses[0].get_passengerSeats(), this->buses[0].get_totalSeats(), this->buses[0].get_destination());
                else
                    newBuses->set_busData(this->buses[1].get_brand(), this->buses[1].get_model(), this->buses[1].get_passengerSeats(), this->buses[1].get_totalSeats(), this->buses[1].get_destination());
                delete[] this->buses;
                this->buses = newBuses;
                --(this->busCount);
            }
            else
            {
                Bus* newBuses = new Bus[busCount - 1];
                for (int i = 0; i < busCount; ++i)
                {
                    if (i != index)
                    {
                        newBuses[j] = this->buses[i];
                        ++j;
                    }
                    else
                    {
                        continue;
                    }
                }
                delete[] this->buses;
                this->buses = newBuses;
                --(this->busCount);
            }
        }
    }
    void Garage::listVehiclesInGarage()
    {
        std::cout << "Cars:" << std::endl;
        for (int i = 0; i < carCount; ++i)
        {
            std::cout << "\t" << (i + 1)
            << ". Brand:" << this->cars[i].get_brand()
            << ", Model:" << this->cars[i].get_model() 
            << ", Engine volume:" << this->cars[i].get_engineVolume()
            << ", Color:" << this->cars[i].get_color()
            << ", Checkpoint type:" << this->cars[i].get_checkpointType() << std::endl;
        }

        std::cout << "Motorcycles: " << std::endl;
        for (int i = 0; i < motorcycleCount; ++i)
        {
           std::cout << "\t" << i + 1 << ". Brand:" << this->motorcycles[i].get_brand()
            << ", Model:" << this->motorcycles[i].get_model()
            << ", Engine volume:" << this->motorcycles[i].get_engineVolume()
            << ", Horsepower:" << this->motorcycles[i].get_horsepower()
            << ", Preferred terrain:" << this->motorcycles[i].get_preferredTerrain() << std::endl;
        }

        std::cout << "Buses: " << std::endl;
        for (int i = 0; i < busCount; ++i)
        {
            std::cout << "\t" << i + 1 << ". Brand:" << this->buses[i].get_brand()
            << ", Model:" << this->buses[i].get_model()
            << ", Passenger seats:" << this->buses[i].get_passengerSeats()
            << ", Total seats:" << this->buses[i].get_totalSeats()
            << ", Destination:" << this->buses[i].get_destination() << std::endl;
        }
    }
    void Garage::saveToFile(std::string filename)
    {
        std::ofstream saveFile(filename);
        saveFile << this->carCount << "\n";
        for (int i = 0; i < this->carCount; ++i)
        {
            saveFile << this->cars[i].get_brand() << "\n" 
                     << this->cars[i].get_model() << "\n"
                     << this->cars[i].get_engineVolume() << "\n"
                     << this->cars[i].get_color() << "\n"
                     << this->cars[i].get_checkpointType() << "\n";
        }

        saveFile << this->motorcycleCount << "\n";
        for (int i = 0; i < this->motorcycleCount; ++i)
        {
            saveFile << this->motorcycles[i].get_brand() << "\n" 
                     << this->motorcycles[i].get_model() << "\n"
                     << this->motorcycles[i].get_engineVolume() << "\n"
                     << this->motorcycles[i].get_horsepower() << "\n"
                     << this->motorcycles[i].get_preferredTerrain() << "\n";
        }

        saveFile << this->busCount << "\n";
        for (int i = 0; i < this->busCount; ++i)
        {
            saveFile << this->buses[i].get_brand() << "\n" 
                     << this->buses[i].get_model() << "\n"
                     << this->buses[i].get_passengerSeats() << "\n"
                     << this->buses[i].get_totalSeats() << "\n"
                     << this->buses[i].get_destination() << "\n";
        }
        saveFile.close();
    }
    Garage Garage::loadFromFile(std::string filename)
    {
        std::ifstream loadFile(filename);
        Garage container;
        unsigned int altCountCar;
        unsigned int altCountMotorcycle;
        unsigned int altCountBus;
        std::string str;
        std::string data[5];
        loadFile >> str;
        altCountCar = stoi(str);
        
        for (int i = 0; i < altCountCar; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                loadFile >> data[j];
            }
            container.addCar(data[0], data[1], stoi(data[2]), data[3], data[4]);
        }

        loadFile >> str;
        altCountMotorcycle = stoi(str);
        
        for (int i = 0; i < altCountMotorcycle; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                loadFile >> data[j];
            }
            container.addMotorcycle(data[0], data[1], stoi(data[2]), stoi(data[3]), data[4]);
        }

        loadFile >> str;
        altCountBus = stoi(str);
        
        for (int i = 0; i < altCountBus; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                loadFile >> data[j];
            }
            container.addBus(data[0], data[1], stoi(data[2]), stoi(data[3]), data[4]);
        }


        loadFile.close();

        return container;
    }
    Garage::Vehicle::Vehicle()
    {
        this->brand = "";
        this->brand = "";
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
    Garage::Car::Car(Car &car)
    {
        this->set_carData(car.get_brand(), car.get_model(), car.get_engineVolume(), car.get_color(), car.get_checkpointType());
    }
    Garage::Car::Car(std::string brand, std::string model, unsigned int liters, std::string color, std::string type): Vehicle(brand, model)
    {
        this->engineVolume = liters;
        this->color = color;
        this->checkpointType = type;
    }
    void Garage::Car::sayHi()
    {
        std::cout << "Hi Car\n";
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
    void Garage::Car::set_carData(std::string brand, std::string model, unsigned int liters, std::string color, std::string type)
    {
        this->set_brand(brand);
        this->set_model(model);
        this->engineVolume = liters;
        this->color = color;
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
    Garage::Motorcycle::Motorcycle()
    {
        this->engineVolume = 0;
        this->horsepower = 0;
        this->preferredTerrain = "";
    }
    Garage::Motorcycle::Motorcycle(Motorcycle &motorcycle)
    {
        this->set_motorcycleData(motorcycle.get_brand(), motorcycle.get_model(), motorcycle.get_engineVolume(), motorcycle.get_horsepower(), motorcycle.get_preferredTerrain());
    }
    Garage::Motorcycle::Motorcycle(std::string brand, std::string model, unsigned int liters, unsigned int power, std::string terrain): Vehicle(brand, model)
    {
        this->engineVolume = liters;
        this->horsepower = power;
        this->preferredTerrain = terrain;
    }
    void Garage::Motorcycle::sayHi()
    {
        std::cout << "Hi Motorcycle\n";
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
    void Garage::Motorcycle::set_motorcycleData(std::string brand, std::string model, unsigned int liters,  unsigned int power, std::string terrain)
    {
        this->set_brand(brand);
        this->set_model(model);
        this->engineVolume = liters;
        this->horsepower = power;
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
    Garage::Bus::Bus()
    {
        this->passengerSeats = 0;
        this->totalSeats = 0;
        this->destination = "";
    }
    Garage::Bus::Bus(Bus &bus)
    {
        this->set_busData(bus.get_brand(), bus.get_model(), bus.get_passengerSeats(), bus.get_totalSeats(), bus.get_destination());
    }
    Garage::Bus::Bus(std::string brand, std::string model, unsigned int passengerSeats, unsigned int totalSeats, std::string destination): Vehicle(brand, model)
    {
        this->passengerSeats = passengerSeats;
        this->totalSeats = totalSeats;
        this->destination = destination;
    }
    void Garage::Bus::sayHi()
    {
        std::cout << "Hi Bus\n";
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
    void Garage::Bus::set_busData(std::string brand, std::string model, unsigned int passengerSeats, unsigned int totalSeats, std::string destination)
    {
        this->set_brand(brand);
        this->set_model(model);
        this->passengerSeats = passengerSeats;
        this->totalSeats = totalSeats;
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