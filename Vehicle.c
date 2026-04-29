#include "Vehicle.h"
#include "FileHelper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*=================== Vehicle Inventory Functions ===================*/
/*------------------- addVehicles -------------------*/
void addVehicles (vehicleInventory listCar[], int *carCount) {
	vehicleInventory addCar;
	if (*carCount<MAX_CARS) {
		printf ("\n --- ADD A NEW CAR --- \n");
		printf ("- Input Car Brand: ");
		scanf ("%s", addCar.Brand);
		printf ("- Input Car Model: ");
		scanf ("%s", addCar.Model);
		printf ("- Input Car Year: ");
		scanf ("%d", &addCar.Year);
		printf ("- Input Car Daily Rate: ");
		scanf ("%lf", &addCar.DailyRate);
		// check Daily Rate
		while (addCar.DailyRate<500) {
			printf ("ERROR! MINI 500$\n");
			printf ("- Input Car Daily Rate: ");
			scanf ("%lf", addCar.DailyRate);
		}
		// Auto-generate Car ID (RCxxx)
		char newCarID [10];
		sprintf(newCarID, "RC%03d", *carCount+1);
		strcpy(addCar.CarID, newCarID);
		// Set status
		printf ("- Status of Car: \"Available\"\n");
		addCar.Status= AVAILABLE;
		// Save car in list car
		listCar[*carCount]=addCar;
		(*carCount)++;
		// successful
		printf ("\n--- CAR ADDED SUCCESSFUL! |(0)-(0)| ---\n");
		// Save data
		saveCar (listCar, *carCount);
	}
	else printf ("CAR LIST IS FULL!");
	
}

/*------------------- removeCar -------------------*/


/*------------------- updateRentalRate -------------------*/