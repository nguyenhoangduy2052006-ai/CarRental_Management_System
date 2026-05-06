#ifndef SEARCH_H
#define SEARCH_H
#include "Vehicle.h"
#include "Rental.h"
#include <stdio.h>
#include <string.h>


/*=================== search & sort Functions ===================*/
/*------------------- toUpperStr -------------------*/
void toUpperStr (char *str);
/*------------------- binarySearchCar -------------------*/
int binarySearchCar (vehicleInventory listCar[], int carCount, char carID[]);

/*------------------- binarySearchRental -------------------*/
int binarySearchRental (rentalTracking rentalsList[], int rentalCount, char rentalID[]);


/*------------------- SearchByBrand -------------------*/
void searchByBrand (vehicleInventory listCar[], int carCount);

/*------------------- SearchByCarID -------------------*/
void searchByCarID (vehicleInventory listCar[], int carCount);


/*------------------- isValidRentalID -------------------*/
int isValidRentalID (char rentalID[]);
/*------------------- SearchByRentalID -------------------*/
void searchByRentalID (rentalTracking rentalsList[], int rentalCount);


/*------------------- SortByBrand -------------------*/
void sortByBrand (vehicleInventory listCar[], int carCount);



#endif