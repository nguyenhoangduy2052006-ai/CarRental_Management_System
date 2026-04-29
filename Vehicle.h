#ifndef VEHICLE_H
#define VEHICLE_H
#include <stdio.h>
#include <string.h>

#define MAX_CARS 100
#define AVAILABLE 0
#define RENTED 1
#define MAINTENANCE 2
#define COMPLETED 3

/*=================== Struct ===================*/
typedef struct {
	char CarID[10]; // RC001, RC002,...
	char Brand[20];
	char Model[20];
	int Year;
	double DailyRate;
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