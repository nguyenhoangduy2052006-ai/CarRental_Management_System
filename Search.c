//================ Declare library =================== 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//================ Declare files ===================  
#include "FileHelper.h"
#include "Search.h"
#include "Vehicle.h"
#include "Rental.h"

/*=================== search & sort Functions ===================*/
/*------------------- toUpperStr -------------------*/
void toUpperStr (char *str) {
	for (int i=0; str[i]!='\0'; i++) {
		str[i]=toupper(str[i]);
	}
}

/*------------------- binarySearchCar -------------------*/
int binarySearchCar (vehicleInventory listCar[], int carCount, char carID[]) {
	int left=0, right=carCount-1; 
	int mid;
	while (left<=right) {
		mid=(left+right)/2;
		int cmp = strcmp(listCar[mid].CarID, carID);
		if (cmp==0) return mid;
		if (cmp<0) left=mid+1;
		if (cmp>0) right=mid-1;
	}
	return -1; // if don't see
}
/*------------------- binarySearchRental -------------------*/
int binarySearchRental (rentalTracking rentalsList[], int rentalCount, char rentalID[]) {
	int left=0, right =rentalCount - 1;
	int mid;
	while (left<=right) {
		mid=(left+right)/2;
		int cmp=strcmp(rentalsList[mid].RentalID, rentalID);
		if (cmp==0) return mid;
		if (cmp<0) left=mid+1;
		if (cmp>0) right=mid-1;
	}
	return -1;
}

/*------------------- SearchByBrand -------------------*/
void searchByBrand (vehicleInventory listCar[], int carCount) {
	char brand[20];
	char brandUpper[20];
	char carBrandUpper[20];
	int valid=0;
	int found=0;
	printf ("\n\t\t === SEARCH CAR BY BRAND ===\n");
	// Valid input
	printf ("- Input Car Brand: ");
	do {
		scanf ("%s", brand);
		if (strlen(brand)==0) printf ("\"ERROR! ENTER BRAND AGAIN.\"\n");
		else if (strlen(brand)>19) printf ("\"ERROR! BRAND ONLY <= 20 CHARACTERS.\"\n");
		else valid=1;
	} while (valid==0);
	
	strcpy(brandUpper, brand);
	toUpperStr(brandUpper);
	// Find cars by brand name
	printf ("%-10s %-15s %-15s %-12s %-15s\n", "CAR ID", "BRAND", "MODEL", "DAILY RATE", "STATUS");
	printf ("------------------------------------------------------------------------------------\n");
	for (int i=0; i<carCount; i++) {
		strcpy(carBrandUpper, listCar[i].Brand);
		toUpperStr(carBrandUpper);
		if (strcmp(carBrandUpper, brandUpper)==0) {
			printf ("%-10s %-15s %-15s %-12.2lf %-15s\n",
			listCar[i].CarID,
			listCar[i].Brand,
			listCar[i].Model,
			listCar[i].DailyRate,
			getStatusLabel(listCar[i].Status));
			found++;
		}
	}
	if (found==0) printf ("\"NO CARS FOUND\" :<\n");
}

/*------------------- SearchByCarID -------------------*/
void searchByCarID (vehicleInventory listCar[], int carCount) {
	char carID[10];
	int valid=0;
	int found=0;
	printf ("\n\t\t === SEARCH BY CAR ID ===\n");
	// Check format
	do {
		printf ("- Input Car ID: ");
		scanf ("%s", carID);
		if (carID[0]=='R' && carID[1]=='C'&&
		isdigit(carID[2]) && isdigit(carID[3]) && isdigit(carID[4]) && carID[5]=='\0') {
			valid=1;
			}
			if (valid==0) printf("ERROR! WRONG FORMAT (RCxxx)\n");
		
	} while (valid==0);
	// Find from Car ID
	printf ("%-10s %-15s %-15s %-12s %-15s\n", "CAR ID", "BRAND", "MODEL", "DAILY RATE", "STATUS");
	printf ("------------------------------------------------------------------------------------\n");
	/*for (int i=0; i<carCount; i++) {
		if (strcmp(listCar[i].CarID, carID)==0) {
			printf ("%-10s %-15s %-15s %-12.2lf %-15s\n",
			listCar[i].CarID,
			listCar[i].Brand,
			listCar[i].Model,
			listCar[i].DailyRate,
			getStatusLable(listCar[i].Status));
			found=1; // Nếu lặp như thế này thì bị một nhược điểm là tốn thời gian tìm kiếm 
		}
		if (found==0) printf ("ERROR! CAR ID IS NOT EXIST.\n");
	}
	*/
	int pos = binarySearchCar(listCar, carCount, carID);
	if (pos!= -1) {
		printf ("%-10s %-15s %-15s %-12.2lf %-15s\n",
			listCar[pos].CarID,
			listCar[pos].Brand,
			listCar[pos].Model,
			listCar[pos].DailyRate,
			getStatusLabel(listCar[pos].Status));
	}
	else printf ("ERROR! CAR ID IS NOT EXIST.\n");
}

/*------------------- isValidRentalID -------------------*/
int isValidRentalID (char rentalID[]) {
	if (rentalID[0]!='N' || rentalID[1]!='H'|| rentalID[2]!='D') return 0;
	int len=strlen(rentalID);
	if (len<=3) return 0; // Because not have number in the back
	for (int i=3; i<len; i++) {
		if (!isdigit(rentalID[i])) return 0;
	}
	return 1;
}
/*------------------- SearchByRentalID -------------------*/
void searchByRentalID (rentalTracking rentalsList[], int rentalCount) {
	char rentalID[10];
	int valid;
	printf ("\n\t\t === SEARCH CAR BY RENTAL ID ===\n\n");
	// Check format
	do {
		printf ("- Input Rental ID: ");
		scanf ("%s", rentalID);
		valid=isValidRentalID (rentalID);
	} while (valid==0);
	
	// Check rental ID exist?
	
	int pos=binarySearchRental(rentalsList, rentalCount, rentalID);
	if (pos!=-1) {
		// Display customer infor
		printf ("=== CUSTOMER INFORMATION ===\n");
		printf  ("%-20s %-15s %-20s\n", "NAME", "PHONE", "ID CARD");
		printf ("---------------------------------------------------------------------\n");
		printf ("%-20s %-15s %-20s\n", rentalsList[pos].Customer.Name,
		rentalsList[pos].Customer.Phone,
		rentalsList[pos].Customer.IDCard);
		// Display rental ID infor
		printf ("\n");
		printf ("=== RENTAL INFORMATION ===\n");
		printf ("%-10s %-10s %-12s %-15s %-10s %-10s\n", "RENTAL ID", "DURATION", "DAILY RATE", "STATUS", "DISCOUNT", "FINAL COST");
		printf ("------------------------------------------------------------------------------------------------------------------------------------\n");
		printf ("%-10s %-10d %-12.2lf %-15s %-10.2lf%% %-10.2lf\n",
			rentalsList[pos].RentalID,
			rentalsList[pos].Duration,
			rentalsList[pos].DailyRate,
			getStatusLabel(rentalsList[pos].Status),
			rentalsList[pos].Discount*100,
			rentalsList[pos].FinalCost);
	}
	else printf ("ERROR! RENTAL ID IS NOT EXIST.\n");
}
 
                                       
/*------------------- SortByBrand -------------------*/
void sortByBrand (vehicleInventory listCar[], int carCount) {
	//Check empty?
	printf ("\n\t\t === SORT CAR BY BRAND ===\n");
	if (carCount==0) {
		printf ("ERROR! NOT FOUND CAR (INVENTORY EMPTY).\n");
		return;
	}
	// Sort by bubble method (A to Z)
	vehicleInventory temp;
	for (int i=0; i<carCount-1; i++) {
		for (int j=0; j<carCount-1-i; j++) {
			if (strcmp(listCar[j].Brand, listCar[j+1].Brand)>0) {
				temp=listCar[j];
				listCar[j]=listCar[j+1];
				listCar[j+1]=temp;
			}
		}
	}
	// Display brand list sorted
	printf ("\n%-5s %-15s %-20s %-15s %-10s %-15s\n", 
	"#", "CAR ID", "BRAND", "MODEL", "YEAR", "STATUS");
	for (int i=0; i<carCount; i++) {
		printf ("%-5d %-15s %-20s %-15s %-10d %-15s\n",
		i+1, listCar[i].CarID,
		listCar[i].Brand,
		listCar[i].Model,
		listCar[i].Year,
		getStatusLabel(listCar[i].Status));
	}
}





