//============================================================================
// Name        : Car Rental System
// Author      : DWI
// Version     :
// Copyright   : Your copyright notice
// Description : Car Rental system exercise
//============================================================================

/* INCLUDES */
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "json/json.h"
#include <algorithm>

/* CONST EXPRESSIONS */
const std::string JSON_FILE_PATH{ "/home/daniel12234/workareas/general-playground/cpp/exercises/carRental/cars.json" };

/* FUNCTION PROTOTYPES */
static int menu_options();
static void home_menu();
static void addCar();
static void updateCar();
static void showCars();
static void checkCar();
static void removeCar();
static void addRentRecord();
static void changeRentRecords();
static void showRentRecords();
static void perform_action(const int& option);
static bool writeToJson(Json::Value newData);
Json::Value take_car_record();

/* MAIN */
int main()
{
    std::cout<<"*** WELCOME ***"<<std::endl;
    std::string decision{ "" };

    while (true)
    {
        std::cout<<" --- CAR RENTAL SYSTEM ---"<<std::endl;
        home_menu();
        std::cout<<"Do you want to continue? (y/n): ";
        std::cin>>decision;

        if (decision=="y")
        {
            break;
        }
    }

}

/* HELPER FUNCTIONS */
void get_car_name(std::string& newCarName)
{
    std::cout<<" Enter car name "<<std::endl;
    std::cin>>newCarName;

    if (newCarName=="")
    {
        std::cout<<" Wrong name, enter again "<<std::endl;
        std::cin>>newCarName;
    }
}

void updateCar()
{
    std::cout<<" --- Update car ---"<<std::endl;
    std::string carNameForUpdate{ "" };
    get_car_name(carNameForUpdate);

    Json::Value listOfCars = take_car_record();

    bool recordFound{ false };
    for (auto& car:listOfCars)
    {
        const std::string carName = car [ "name" ].asString();
        std::transform(carNameForUpdate.begin(),
            carNameForUpdate.end(),
            carNameForUpdate.begin(),
            ::toupper);

        if (carNameForUpdate==carName)
        {
            /* Perform update */
            std::string name, model, rentPrice;

            std::cout<<"New Name: ";
            std::getline(std::cin, name);

            std::cout<<"Car Model: ";
            std::getline(std::cin, model);

            std::cout<<"Rent Price: ";
            std::getline(std::cin, rentPrice);

            car [ "name" ] = name;
            car [ "model" ] = model;
            car [ "rentPrice" ] = rentPrice;

            writeToJson(listOfCars);
            recordFound = true;
            break;
        }
        else
        {
            continue;
        }

        if (recordFound==true)
        {
            std::cout<<"Car updated\n";
        }
        else
        {
            std::cout<<"Car not found\n";
        }
    }
}

Json::Value take_car_record()
{
    std::ifstream file(JSON_FILE_PATH, std::ifstream::binary);
    if (!file)
    {
        std::cerr<<"Input file with cars not opened"<<std::endl;
        return false;
    }

    Json::Value handler;
    file>>handler;

    file.close();
    return handler;
}

static bool writeToJson(Json::Value newData)
{
    std::ofstream file{ JSON_FILE_PATH };
    if (!file)
    {
        std::cerr<<"Input file with cars not opened"<<std::endl;
        return false;
    }

    file<<newData;
    file.close();
    return true;
}

void addCar()
{
    Json::Value listOfCars = take_car_record();

    std::string carName, model, rentPrice, carId;
    std::cout<<std::endl<<" --- Provide car details ---"<<std::endl;
    std::cout<<"Car Name: ";
    std::cin>>carName;
    std::cout<<"Car Model: ";
    std::cin>>model;
    std::cout<<"Rent Price: ";
    std::cin>>rentPrice;

    std::string lastCar = std::to_string(listOfCars.size()+1);
    std::string carNumber = "A00"+lastCar;

    Json::Value newRecord;
    newRecord [ "id" ] = lastCar;
    newRecord [ "name" ] = carName;
    newRecord [ "carNumber" ] = carNumber;
    newRecord [ "model" ] = model;
    newRecord [ "rentPrice" ] = rentPrice;

    listOfCars.append(newRecord);

    if (writeToJson(listOfCars))
    {
        std::cout<<"CAR ADDED"<<std::endl;
    }
    else
    {
        std::cerr<<"ERROR. CAR NOT ADDED"<<std::endl;
    }

}

void showCars()
{
    std::cout<<" --- List of the cars ---"<<std::endl;
    Json::Value listOfCars = take_car_record();
    short i{ 0 };

    std::cout<<"No. | Car Name | Car No. | Model | Rent Price (per day)"<<std::endl;
    for (auto car:listOfCars)
    {
        std::string name = car [ "name" ].asString();
        std::string num = car [ "carNumber" ].asString();
        std::string model = car [ "model" ].asString();
        std::string rentPrice = car [ "rentPrice" ].asString();

        // TODO: Implement allegement here!
        std::cout<<i++<<".   "<<name<<"  "<<num<<"    "<<model<<"   $"<<rentPrice<<std::endl;
    }
}

void perform_action(const int& option)
{
    switch (option) {
    case 1:
        checkCar();
        break;
    case 2:
        addCar();
        break;
    case 3:
        updateCar();
        break;
    case 4:
        removeCar();
        break;
    case 5:
        showCars();
        break;
    case 6:
        addRentRecord();
        break;
    case 7:
        changeRentRecords();
        break;
    case 8:
        showRentRecords();
        break;
    }
}

int menu_options()
{
    std::cout<<"1. Car Enquiry"<<std::endl;
    std::cout<<"2. New Car"<<std::endl;
    std::cout<<"3. Modify Car"<<std::endl;
    std::cout<<"4. Remove Car"<<std::endl;
    std::cout<<"5. Show All Cars"<<std::endl;
    std::cout<<"6. Rent a Car"<<std::endl;
    std::cout<<"7. Change Rent Records"<<std::endl;
    std::cout<<"8. Show Rent Records"<<std::endl;
    std::cout<<"0. Exit"<<std::endl;
    std::cout<<"--- Choose any one option ---"<<std::endl;
    std::cout<<"Enter one optiostd::n: ";

    int selectedOption{ 0 };
    std::cin>>selectedOption;
    return selectedOption;
}

static void home_menu()
{
    int option = menu_options();

    if (option>=1&&option<=8)
    {
        /* do specific operation with option */
        perform_action(option);
    }
    else if (option==0)
    {
        exit(0);
    }
    else
    {
        std::cout<<"Enter valid option please "<<std::endl;
        option = menu_options();
    }
}

static void checkCar()
{
    std::cout<<"Functionality not supported now"<<std::endl;
}
static void removeCar()
{
    std::cout<<"Functionality not supported now"<<std::endl;
}
static void addRentRecord()
{
    std::cout<<"Functionality not supported now"<<std::endl;
}
static void changeRentRecords()
{
    std::cout<<"Functionality not supported now"<<std::endl;
}
static void showRentRecords()
{
    std::cout<<"Functionality not supported now"<<std::endl;
}