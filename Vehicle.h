#ifndef VEHICLE_H
#define VEHICLE_H
#include <stdio.h>
#include <string.h>

#define Max_Cars 100
#define Available 0
#define Rented 1
#define Maintenance 2
#define Completed 3

/*=================== Struct ===================*/
typedef struct {
	char CarID[10]; // RC001, RC002,...
	char Brand[20];
	char Model[20];
	int year;
	float DailyRate;
	int Status; // Available=0, Rented=1, Maintenance=2

} vehicleInventory;

/*=================== Vehicle Inventory Functions ===================*/
/*------------------- addVehicles -------------------*/
void addVehicles (vehicleInventory listCar[], int *carCount);

/*------------------- removeCar -------------------*/
void removeCar (vehicleInventory listCar[], int *carCount);

/*------------------- updateRentalRate -------------------*/
void updateRentalRate (vehicleInventory listCar[], int carCount);





#endif