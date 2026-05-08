//================ Declare library =================== 
#include <stdio.h>
#include <string.h>
//================ Declare files ===================
#include "Tracking.h"
#include "Vehicle.h"
#include "Rental.h"

/*=================== Report Functions ===================*/
/*------------------- checkMaintenance -------------------*/
void checkMaintenance (vehicleInventory listCar[], int carCount) {
	vehicleInventory maintenanceList[MAX_CARS];
	// Check inventory empty?
	if (carCount==0) {
		printf ("\n\"NO CARS TO CHECK (INVENTORY EMPTY)\"\n");
		return;
	}
	// Check maintenance
	int maintenanceCount=0;
	for (int i=0; i<carCount; i++) {
		if (listCar[i].Status==MAINTENANCE) {
			maintenanceList[maintenanceCount]=listCar[i];
			maintenanceCount++;
		}
	}
	if (maintenanceCount==0) {
		printf ("\n\"NO CARS IN MAINTENANCE\"\n");
		return;
	}
	printf ("\n\t\t === MAINTENANCE CARS LIST ===\n\n");
	printf ("%-10s %-15s %-20s %-8s %-12s %-15s\n", "CAR ID", "BRAND", "MODEL", "YEAR", "DAILY RATE", "STATUS");
	printf ("-------------------------------------------------------------------------------------------------------------------------\n");
	for (int k=0; k<maintenanceCount; k++) {
		printf ("%-10s %-15s %-20s %-8d %-12.2lf %-15s\n",
		maintenanceList[k].CarID,
		maintenanceList[k].Brand,
		maintenanceList[k].Model,
		maintenanceList[k].Year,
		maintenanceList[k].DailyRate,
		getStatusLabel(maintenanceList[k].Status));
	}
}

/*------------------- revenueReport -------------------*/
void revenueReport (rentalTracking rentalsList[], int rentalCount) {
    double totalRevenue=0;
    // Check rental count
    if (rentalCount==0) {
        printf ("\n\"NO RENTAL RECORDS\"\n");
        return;
    }
    // Calculate total revenue
    for (int i=0; i<rentalCount; i++) {
        if (rentalsList[i].Status==COMPLETED) {
            totalRevenue+=rentalsList[i].FinalCost;
        }
    }
    // Display total revenue
    printf ("\n\t\t === TOTAL REVENUE OF THE SHOP |(0)-(0)| ===\n\n");
    printf ("TOTAL REVENUE: %.2lf$\n", totalRevenue);
}