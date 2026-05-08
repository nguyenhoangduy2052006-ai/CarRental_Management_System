#ifndef TRACKING_H
#define TRACKING_H
//================ Declare library =================== 
#include <stdio.h>
#include <string.h>
//================ Declare files ===================
#include "FileHelper.h"
#include "Vehicle.h"
#include "Rental.h"


/*=================== Report Functions ===================*/
/*------------------- checkMaintenance -------------------*/
void checkMaintenance (vehicleInventory listCar[], int carCount);

/*------------------- revenueReport -------------------*/
void revenueReport (rentalTracking rentalsList[], int rentalCount);


#endif
