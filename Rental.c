//================ Declare files ===================  
#include "Rental.h"
#include "Vehicle.h"
#include "FileHelper.h"
//================ Declare library =================== 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*=================== Rental Functions ===================*/
/*------------------- validRentalID -------------------*/
/*void validRentalID (rentalTracking rentalsList[], int rentalCount) {
	char rentalID[10];
	int pos=-1;
	double cost;
	printf ("- Input Rental ID: ");
	scanf ("%s", rentalID);
	// valide Rental ID
	for (int i=0; i<rentalCount; i++) {
		if (strcmp(rentalID, rentalsList[i].RentalID)==0) {
			pos=i;
			break;
		}
	}
	if (pos==-1) {
		printf ("\"ERROR! NOT FOUND RENTAL ID\"");
		return;
	}
}*/
/*------------------- rentalDiscount -------------------*/
double rentalDiscount (int duration) {
	if (duration>=30) return 0.2;
	else if (duration>=7) return 0.1;
	else return 0.0;
}

/*------------------- calculateCostRental -------------------*/
void calculateCostRental (rentalTracking *cost) {
	cost->Cost=(cost->DailyRate)*(cost->Duration);
	cost->Discount= rentalDiscount(cost->Duration);
	cost->FinalCost=cost->Cost * (1-(cost->Discount));
}

/*------------------- returnCar -------------------*/
void returnCar (rentalTracking rentalsList[], int *rentalCount, vehicleInventory listCar[], int carCount) {
	char rentalID[10];
	int pos=-1;
	printf ("\n\t\t --- RETURN CAR --- |(0)-(0)|\n");
	printf ("- Input Rental ID: ");
	scanf ("%s", rentalID);
	// check rentalID
	for (int i=0; i<*rentalCount; i++) {
		if (strcmp(rentalID, rentalsList[i].RentalID)==0) {
			pos=i;
			break;
		}
	}
	if (pos==-1) {
		printf ("ERROR! NOT FOUND RENTAL ID.\n");
		return;
	}
	// Check Status
	if (rentalsList[pos].Status!=1) {
		printf ("ERROR! CAR NOT CURRENTLY RENTED");
		return;
	}
	// Update status
	rentalsList[pos].Status=COMPLETED; // 0 is Available
	char carID[10];
	strcpy(carID, rentalsList[pos].CarID);
	for (int i=0; i<carCount; i++) {
		if (strcmp(carID, listCar[i].CarID)==0) {
			listCar[i].Status=AVAILABLE;
			saveCar(listCar, carCount);
			break;
		}
	}
	// Delete amount car in rental list
	
	// Save into file
	saveRental (rentalsList, *rentalCount);
	
	printf ("\n\t\t --- CAR RETURNED SUCCESSFULLY! ---\n\t\t|(0)-(0)|\n");
}

/*------------------- assignCar -------------------*/
void assignCar (rentalTracking rentalsList[], int *rentalCount, vehicleInventory listCar[], int carCount); // number of rental car list will be added in list

/*------------------- displayRentalCarList -------------------*/
void displayRentalCarList (rentalTracking rentalsList[], int rentalCount);

/*------------------- fileterByPrice -------------------*/
void fileterByPrice (vehicleInventory listCar[], int carCount);