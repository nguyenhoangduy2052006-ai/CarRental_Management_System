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
		printf ("\n\t\t --- ADD A NEW CAR --- |(0)-(0)|\n\n");
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
void removeCar (vehicleInventory listCar[], int *carCount) {
	char deleteCar[10];
	printf ("\n\t\t --- REMOVE CAR --- |(0)-(0)|\n\n");
	printf ("- Input car ID need remove: ");
	scanf ("%s", deleteCar); 
	int pos=-1;
	for (int i=0; i<*carCount; i++) {
		if (strcmp(deleteCar, listCar[i].CarID)==0) {
			pos=i;
			break;
		}
	}
	if (pos==-1) {
		printf ("ERROR! CAR NOT FOUND.");
		return;
	}
	if (listCar[pos].Status!=AVAILABLE) {
		printf ("ERROR! CAR RENTED OR MAINTENANCE |(0)-(0)|");
		return;
	}
	for (int j=pos; j<*carCount-1; j++) {
		listCar[j]=listCar[j+1];
	}
	(*carCount)--;
	// Save 
	saveCar (listCar, *carCount);
	printf ("CAR REMOVED SUCCESSFULLY! |(0)-(0)|\n");
	
}

/*------------------- updateRentalRate -------------------*/
void updateRentalRate (vehicleInventory listCar[], int carCount) {
	printf ("\n\t\t--- UPDATE RENTAL RATE --- |(0)-(0)|\n\n");
	double newRate;
	char carID[10];
	int pos=-1;
	// Input Car ID
	printf ("- Input Car ID: ");
	scanf ("%s", carID);
	for (int i=0; i<carCount; i++) {
		if (strcmp(carID, listCar[i].CarID)==0) {
			pos=i;
			break;
		}
	}
	if (pos==-1) {
		printf ("ERROR! NOT FOUND CAR ID\n");
		return;
	}
	// Input new rental rate
	printf ("- Current Rental Rate: %.2lf\n", listCar[pos].DailyRate);
	do {
		printf ("- Change Rental Rate: ");
		scanf ("%lf", &newRate);
		if (newRate<500) {
			printf ("ERROR! MIN DAILY RATE >= 500$\n");
		}
	} while (newRate<500);
	listCar[pos].DailyRate=newRate;
	// Save
	saveCar (listCar, carCount);
	printf ("\n\t\tUPDATE DAILY RATE SUCCESSFULLY! |(0)-(0)|\n");
}







