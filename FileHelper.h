#ifndef FILEHELPER_H
#define FILEHELPER_H
#include "Vehicle.h"
#include "Rental.h"

/*=================== loadCar ===================*/
void loadCar (vehicleInventory listCar[], int *carCount);

/*=================== loadRental ===================*/
void loadRental (rentalTracking rentalsList[], int *rentalCount);

/*=================== saveCar ===================*/
void saveCar (vehicleInventory listCar[], int carCount);

/*=================== saveRental ===================*/
void saveRental (rentalTracking rentalsList[], int rentalCount);

#endif