#ifndef RENTAL_H
#define RENTAL_H
#include "Vehicle.h"
#include <stdio.h>
#include <string.h>
#define MAX_RENTALS 100
// Define discount
#define LUXURY 1500
#define PRIMIUM 1000
#define MEDIUM 500

/*=================== Struct ===================*/
/*------------------ customerInfor --------------*/
typedef struct {
	char Name [20];
	char Phone[15];
	char IDCard[20];
} customerInfor;

/*------------------ rentalTracking --------------*/
typedef struct {
	char RentalID[10]; // Eg: NHD001, NHD002,...
	char CarID[10];
	customerInfor Customer;
	int Duration; // A time customer rent a car
	int Status; // Available = 0; Rented = 1; Maintenance = 2; Completed = 3 // it is use for revenue report
	double DailyRate;
	double Cost;
	double FinalCost;
	double Discount;
	
} rentalTracking;


/*=================== Rental Functions ===================*/
/*------------------- calculateCostRental -------------------*/
double calculateCostRental (rentalTracking *r);

/*------------------- rentalDiscount -------------------*/
int rentalDiscount (int duration); // a rental time from customer will assgin into duration variable

/*------------------- returnCar -------------------*/
void returnCar (rentalTracking rentalsList[], int *rentalCount, vehicleInventory listCar[], int carCount); // mục đích là số lượng xe thuê sẽ giảm trong danh sách thuê xe, và trạng thái xe sẽ được cập nhật ở kho xe (vehicleInventory) là Available

/*------------------- assignCar -------------------*/
void assignCar (rentalTracking rentalsList[], int *rentalCount, vehicleInventory listCar[], int carCount); // number of rental car list will be added in list

/*------------------- displayRentalCarList -------------------*/
void displayRentalCarList (rentalTracking rentalsList[], int rentalCount);

/*------------------- fileterByPrice -------------------*/
void fileterByPrice (vehicleInventory listCar[], int carCount);



#endif