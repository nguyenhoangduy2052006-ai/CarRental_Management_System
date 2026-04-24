#ifndef SEARCH_H
#define SEARCH_H
#include "Rental.h"
#include "Vehicle.h"
#include <stdio.h>
#include <string.h>


/*=================== search & sort Functions ===================*/
/*------------------- SearchByBrand -------------------*/
void searchByBrand (vehicleInventory listCar[], int carCount, char Brand[]);

/*------------------- SearchByCarID -------------------*/
void searchByCarID (vehicleInventory listCar[], int carCount, char CarID[]);

/*------------------- SearchByRentalID -------------------*/
void searchByRentalID (rentalTracking rentalsList[], int rentalCount, char RentalID[]);

/*------------------- SortByBrand -------------------*/
void sortByBrand (vehicleInventory listCar[], int carCount);


/*=================== Report Functions ===================*/
/*------------------- checkMaintenance -------------------*/
void checkMaintenance (vehicleInventory listCar[], int carCount);

/*------------------- revenueReport -------------------*/
void revenueReport (rentalTracking rentalsList[], int rentalCount);



#endif