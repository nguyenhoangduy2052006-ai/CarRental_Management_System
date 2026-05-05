//================ Declare files ===================  
#include "FileHelper.h"
#include "Vehicle.h"
#include "Rental.h"
//================ Declare library =================== 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*=================== Rental Functions ===================*/
/*------------------- statusLable -------------------*/
const char *getStatusLable (int status) {
	if (status==AVAILABLE) return "AVAILABLE";
	else if (status==RENTED)  return "RENTED";
	else return "MAINTENANCE";
}

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
	
	// Save into file
	saveRental (rentalsList, *rentalCount);
	
	printf ("\n\t\t --- CAR RETURNED SUCCESSFULLY! ---\n\t\t|(0)-(0)|\n");
}

/*------------------- assignCar -------------------*/
void assignCar (rentalTracking rentalsList[], int *rentalCount, vehicleInventory listCar[], int carCount){
	char carID[10];
	customerInfor infor;
	int duration;
	rentalTracking assignInfor;
	printf ("\n\t\t --- ASSIGN CAR ---\n\t\t|(0)-(0)|\n");
	// Input customer infor
	int valid=0;
	do {
		printf ("\n1. Input your information:\n");
		printf ("- Name: ");
		scanf (" %[^\n]", infor.Name);
		printf ("Phone: ");
		scanf (" %[^\n]", infor.Phone);
		printf ("ID card: ");
		scanf (" %[^\n]", infor.IDCard);
		// valid infor 
		if (strlen(infor.Name)==0 ||
		strlen(infor.Phone)==0 ||
		strlen(infor.IDCard)==0) {
			printf ("ERROR! MISSTING INFORMATION.\n");
		} else valid=1;
		// Check amount storage
		if (strlen(infor.Name)>19) {
			printf ("ERROR! MAX NAME IS 20 CHARACTER.");
			valid=0;
		}
		if (strlen(infor.Phone)>14) {
			printf ("ERROR! MAX PHONE NUMBER IS 15 CHARACTER.");
			valid=0;
		}
		if (strlen(infor.IDCard)>19) {
			printf ("ERROR! MAX ID CARD IS 20 CHARACTER.");
			valid=0;
		}
	} while (valid==0);
	// Input car ID
	printf ("2. Input car ID: ");
	int pos=-1;
	do {
		scanf ("%s", carID);
		for (int i=0; i<carCount; i++) {
			if (strcmp(carID, listCar[i].CarID)==0) {
				pos=i;
				break;
			}
		}
		if (pos==-1) printf ("ERROR! NOT FOUND CAR ID.\n");
			// Check status
		if (listCar[pos].Status!=AVAILABLE) {
			printf ("ERROR! CAR NOT AVAILABLE :((\n");
			pos=-1;
	}
	} while (pos==-1);

	// Input Duration
	printf ("3. Input your duration (days): ");
	int d=0;
	do {
		scanf ("%d", &duration);
		if (duration>=1) {
			d=1;
		} else printf ("ERROR! MIN 1 DAY ^^");
	} while (d==0);
	// Create Rental ID
	char newRentalID[10];
	sprintf (newRentalID, "NHD%03d", *rentalCount+1);
	strcpy(assignInfor.RentalID, newRentalID);
	// Set status
	assignInfor.Status=RENTED;
	listCar[pos].Status=RENTED;
	
	strcpy(assignInfor.Customer.Name, infor.Name);
	strcpy(assignInfor.Customer.Phone, infor.Phone);
	strcpy(assignInfor.Customer.IDCard, infor.IDCard);
	strcpy(assignInfor.CarID, carID);
	assignInfor.Duration=duration;
	assignInfor.DailyRate=listCar[pos].DailyRate;
	// Calculate cost
	calculateCostRental (&assignInfor);
	// Save into list Rental
	rentalsList[*rentalCount]=assignInfor;
	(*rentalCount)++;
	// Save rental record
	saveRental (rentalsList, *rentalCount);
	saveCar (listCar, carCount);
	// Display in the minor
	printf ("\n\t\t -- CAR ASSIGN SUCCESSFULLY! --- \n\t\t|(0)-(0)|");
	printf ("- RENTAL ID: %s\n", assignInfor.RentalID);
	printf ("- CAR ID: %s\n", assignInfor.CarID);
	printf ("- DURATION: %d day(s)\n", assignInfor.Duration);
	printf ("- COST: %.2lf$\n", assignInfor.Cost);
	printf ("- DISCOUNT: %.0lf%%\n", assignInfor.Discount*100);
	printf ("- FINAL COST: %.2lf$\n", assignInfor.FinalCost);
}

/*------------------- displayRentalCarList -------------------*/
void displayRentalCarList (vehicleInventory listCar[], int carCount) {
	// Check empty of inventory
	if (carCount==0) {
		printf ("NO CAR FOUND (INVENTORY EMPTY)!\n");
		return;
	}
	// Display header table
	printf ("\n\t\t === LIST OF RENTAL CARS ===\n");
	printf ("%-10s %-20s %-20s %-8s %-12s %-15s\n",
	"CAR ID", "BRAND", "MODEL", "YEAR", "DAILY RATE", "STATUS");
	printf("--------------------------------------------------------------------\n");
	// Print rental car
	char statusLable[15];
	for (int i=0; i<carCount; i++) {
		if (listCar[i].Status==AVAILABLE) strcpy(statusLable, "AVAILABLE");
		else if (listCar[i].Status==RENTED) strcpy(statusLable, "RENTED");
		else strcpy(statusLable, "MAINTENANCE");
		
		printf ("%-10s %-20s %-20s %-8d %-12.2lf %-15s\n",
		listCar[i].CarID, listCar[i].Brand, listCar[i].Model, listCar[i].Year, listCar[i].DailyRate, statusLable);
	}
}

/*------------------- fileterByPrice -------------------*/
void fileterByPrice (rentalTracking rentalsList[], int *rentalCount, vehicleInventory listCar[], int carCount) {
	double budget;
	int check=0;
	printf ("\n\t\t === CHOOSE RENTAL CAR FOLLOW YOUR BUDGET ===\n\t\t|(0)-(0)|\n\n");
	// Check budget>500$?
	do {
		printf ("- Input your budget: ");
		scanf ("%lf", &budget);
		if (budget<500) {
			printf ("\"BUDGET TOO LOW! (<500$)\"\n");
		} else check=1;
	} while (check==0);
	// Check budget>=1500$?
	if (budget>=1500) {
		printf ("\n\t=== LIST OF LUXURY CARS ===\n\n");
		printf ("%-15s %-12s %-15s\n", "CAR ID", "DAILY RATE", "STATUS");
		printf ("--------------------------------------------------------\n");
		for (int i=0; i<carCount; i++) {
			if (listCar[i].DailyRate>=1500) {
				printf ("%-15s %-12.2lf %-15s\n", listCar[i].CarID, listCar[i].DailyRate, getStatusLable(listCar[i].Status));
			}
		}
	}
	// Check budget>=1000$?
	else if (budget>=1000) {
		printf ("\n\t=== LIST OF PREMIUM CARS ===\n\n");
		printf ("%-15s %-12s %-15s\n", "CAR ID", "DAILY RATE", "STATUS");
		printf ("--------------------------------------------------------\n");
		for (int i=0; i<carCount; i++) {
			if (listCar[i].DailyRate>=1000) {
				printf ("%-15s %-12.2lf %-15s\n", listCar[i].CarID, listCar[i].DailyRate, getStatusLable(listCar[i].Status));
			}
		}
	}
	else {
		printf ("\n\t=== LIST OF MEDIUM CARS ===\n\n");
		printf ("%-15s %-12s %-15s\n", "CAR ID", "DAILY RATE", "STATUS");
		printf ("--------------------------------------------------------\n");
		for (int i=0; i<carCount; i++) {
			if (listCar[i].DailyRate>=500) {
				printf ("%-15s %-12.2lf %-15s\n", listCar[i].CarID, listCar[i].DailyRate, getStatusLable(listCar[i].Status));
			}
		}
	}
	// Call assignCar function
	assignCar (rentalsList, rentalCount, listCar, carCount);
	printf ("\n\t\t \"YOU RENTED CAR SUCCESSFULLY!\"\n");
}



