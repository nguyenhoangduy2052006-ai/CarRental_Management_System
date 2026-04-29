#include "FileHelper.h"
#include "Vehicle.h"
#include "Rental.h"
#include <stdio.h>
#include <stdlib.h>

/*=================== READ & LOAD FILE ===================*/
/*------------------- loadCar -------------------*/
void loadCar (vehicleInventory listCar[], int *carCount) {
	FILE *RC = fopen ("Cars_Data.txt", "r");
	if (RC==NULL) {
		printf ("ERROR! CAN NOT OPEN Cars_Data.txt");
		*carCount=0;
		return;
	} 
	fscanf(RC, "%d\n", carCount);
	for (int i=0; i<*carCount; i++) {
		fscanf (RC, "%s %s %s %d %lf %d\n", 
		listCar[i].CarID,
		listCar[i].Brand,
		listCar[i].Model,
		&listCar[i].Year,
		&listCar[i].DailyRate,
		&listCar[i].Status);
	}
	fclose(RC);	
}

/*------------------- loadRental -------------------*/
void loadRental (rentalTracking rentalsList[], int *rentalCount) {
	FILE *RC = fopen ("Rental_Data.txt", "r");
	if (RC==NULL) {
		printf ("ERROR! CAN NOT OPEN Rental_Data.txt");
		*rentalCount=0;
		return;
	}
	fscanf (RC, "%d\n", rentalCount);
	for (int i=0; i<*rentalCount; i++) {
		fscanf (RC, "%s %s %s %s %s %d %d %lf %lf %lf %lf\n",
		rentalsList[i].RentalID,
		rentalsList[i].CarID,
		rentalsList[i].Customer.Name,
		rentalsList[i].Customer.Phone,
		rentalsList[i].Customer.IDCard,
		&rentalsList[i].Duration,
		&rentalsList[i].Status,
		&rentalsList[i].DailyRate,
		&rentalsList[i].Cost,
		&rentalsList[i].FinalCost,
		&rentalsList[i].Discount);
	}
	fclose(RC);
}

/*=================== CREATE & WRITE FILE ===================*/
/*------------------- saveCar -------------------*/
void saveCar (vehicleInventory listCar[], int carCount) {
	FILE *RC = fopen ("Cars_Data.txt", "w");
	// check file open?
	if (RC==NULL) {
		printf ("ERROR! CAN NOT OPEN Cars_Data.txt");
		return;
	}
	fprintf (RC, "%d\n", carCount);
	for (int i=0; i<carCount; i++) {
		fprintf (RC, "%s %s %s %d %.2lf %d\n", 
		listCar[i].CarID,
		listCar[i].Brand,
		listCar[i].Model,
		listCar[i].Year,
		listCar[i].DailyRate,
		listCar[i].Status);
	}
	fclose (RC);
}

/*------------------- saveRental -------------------*/
void saveRental (rentalTracking rentalsList[], int rentalCount) {
	FILE *RC = fopen ("Rental_Data.txt", "w");
	if (RC==NULL) {
		printf ("ERROR! CAN NOT OPEN Rental_Data.txt");
		return;
	}
	fprintf (RC, "%d\n", rentalCount);
	for (int i=0; i<rentalCount; i++) {
		fprintf (RC, "%s %s %s %s %s %d %d %.2lf %.2lf %.2lf %.2lf\n",
		rentalsList[i].RentalID,
		rentalsList[i].CarID,
		rentalsList[i].Customer.Name,
		rentalsList[i].Customer.Phone,
		rentalsList[i].Customer.IDCard,
		rentalsList[i].Duration,
		rentalsList[i].Status,
		rentalsList[i].DailyRate,
		rentalsList[i].Cost,
		rentalsList[i].FinalCost,
		rentalsList[i].Discount);
	}
	fclose(RC);
}
