//================ Declare library =================== 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//================ Declare files ===================  
#include "ConsoleIO.h"
#include "FileHelper.h"
#include "Rental.h"
#include "Vehicle.h"
#include "Search.h"
#include "Tracking.h"

//================ Define  =================== 
#define serverPASSWORD "RC-NHD_20"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	// Declare 
	int carCount=0;
	int rentalCount=0;
	vehicleInventory listCar[MAX_CARS];
	rentalTracking rentalsList [MAX_RENTALS];
	//loadCar
	loadCar (listCar, &carCount);
	//loadRental
	loadRental (rentalsList, &rentalCount);
	// Excute program
	int choice;
	
	do {
		printf ("========== Welcome to RC-NHD Shop ==========\n");
		printf ("\t\t||(0)-(0)||\n\n");
		printf("^^ Click Your Choice ^^\n");
		printf ("1. Customer\n");
		printf ("2. Server\n");
		printf ("0. Exit\n\n");
		scanf ("%d", &choice);
		system ("cls");
		switch (choice) {
			case 1: { // Menu for Customer
				int customerChoice;
				do {
					printf ("\n=================== MENU TO RENTAL CAR ===================\n\n");
					printf ("1. DISPLAY LIST OF RENTAL CAR\n\n");
						
					printf ("2. RETURN CAR\n\n");
						
					printf ("3. FILTER BY PRICE\n\n");
						
					printf ("4. SEARCH BY RENTAL ID\n\n");
						
					printf ("5. SEARCH BY BRAND\n\n");
						
					printf ("6. DISPLAY DISCOUNT TABLE\n\n");
					printf("\n------------------------------------------------------------\n");
						
					printf ("0. EXIT\n\n\n");
						
						
					scanf ("%d", &customerChoice);
					// loop customer choice
					switch (customerChoice) {
						case 0:
							system("cls");
							// display thoát Menu Customer trở về Menu chính
							break;
						case 1: {
							system("cls");
							// gọi hàm hiển thị bảng danh danh ô tô kèm các thông tin của mỗi chiếc ô tô (Car Name, Year, Status,...)	
							displayRentalCarList(listCar, carCount);
							// goi các hàm tính tính tiền cho khách hàng
							printf("\n-------------------------------------------------------------------------------------\n\n");
							printf ("1. RENT A CAR. |(0)-(0)|\n");
							printf ("0. BACK TO MENU\n\n");
							printf ("INPUT YOUR CHOICE: ");
							int rentChoice;
							scanf ("%d", &rentChoice);
							if (rentChoice==1) {
								system ("cls");
								assignCar (rentalsList, &rentalCount, listCar, carCount);
								printf ("\nENTER TO FINISH.");								
							}
							break;
						}

						case 2: {
							// gọi hàm trả về ô tô cho cửa hàng
							system("cls");
							printf("\n---------------------------------------- |(0)-(0)| ----------------------------------------\n\n");
							printf ("1. RETURN A CAR. |(0)-(0)|\n\n");
							printf ("0. BACK TO MENU\n\n");
							printf ("INPUT YOUR CHOICE: ");
							int returnChoice;
							scanf ("%d", &returnChoice);
							if (returnChoice==1) {
								system ("cls");
								returnCar (rentalsList, &rentalCount, listCar, carCount);
							}
							break;
						}

						case 3: {
							system("cls");
							// Fileter rental car by customer's budget
							printf("\n---------------------------------------- |(0)-(0)| ----------------------------------------\n\n");
							printf ("1. FILETER A CAR. |(0)-(0)|\n\n");
							printf ("0. BACK TO MENU\n\n");
							printf ("INPUT YOUR CHOICE: ");
							int fileterChoice;
							scanf ("%d", &fileterChoice);
							if (fileterChoice==1) {
								system ("cls");
								fileterByPrice (rentalsList, &rentalCount, listCar, carCount);
							}
							printf ("\n\n");
							printf ("1. ASSIGN A CAR. |(0)-(0)|\n\n");
							printf ("0. BACK TO MENU\n\n");
							printf ("INPUT YOUR CHOICE: ");
							int assign1Choice;
							scanf ("%d", &assign1Choice);
							if (assign1Choice==1) {
								assignCar (rentalsList, &rentalCount, listCar, carCount);
							}												
							break;
						}

						case 4: {
							system ("cls");
							// gọi hàm tìm kiếm bằng Rental ID
							printf("\n---------------------------------------- |(0)-(0)| ----------------------------------------\n\n");
							printf ("1. SEARCH A CAR BY RENTAL ID. |(0)-(0)|\n\n");
							printf ("0. BACK TO MENU\n\n");
							printf ("INPUT YOUR CHOICE: ");
							int searchRentalIDChoice;
							scanf ("%d", &searchRentalIDChoice);
							if (searchRentalIDChoice==1) {
								system ("cls");
								searchByRentalID (rentalsList, rentalCount);
							}
							break;
						}

						case 5: {
							system("cls");
							// gọi hàm tìm kiếm theo hãng
							printf("\n---------------------------------------- |(0)-(0)| ----------------------------------------\n\n");
							printf ("1. SEARCH A CAR BY BRAND. |(0)-(0)|\n\n");
							printf ("0. BACK TO MENU\n\n");
							printf ("INPUT YOUR CHOICE: ");
							int searchBrandChoice;
							scanf ("%d", &searchBrandChoice);
							if (searchBrandChoice==1) {
								system ("cls");
								searchByBrand (listCar, carCount);
							}	
							break;
						}

						case 6: 
							system("cls");
							printf ("\nINFORMATION ABOUT CAR RENTAL DISCOUNT - |(0)-(0)|\n\n");
							printf ("=======================================================\n\n");
							printf ("- IF CUSTOMER RENT CAR MORE 7 DAYS - DISCOUNT 10%%\n\n");
							printf ("- IF CUSTOMER RENT CAR MORE 30 DAYS - DISCOUNT 20%%\n\n");
							printf ("=======================================================\n\n");
							break;
						default:
							printf ("Error! choose again.\n");
							break;
					}
					if (customerChoice!=0) {
						while (getchar()!='\n');
						getchar();
						system("cls");
					}	
				} while (customerChoice!=0);
				
				break;
			}
			case 2: { // Menu for Admin
				
				char password[15];
				int tries=0;
				do {
					printf ("REQUIRE INPUT PASSWORD: ");
					scanf ("%s", password);
					tries++;
					if (strcmp(password, serverPASSWORD)!=0) {
						printf ("ERROR PASSWORD!\n"); 
						while (getchar()!='\n');
						getchar();
					}
						
					system("cls");
				} while ((strcmp(password, serverPASSWORD)!=0) && tries<3);
				system("cls");
				if (strcmp(password, serverPASSWORD)==0) {
					int serverChoice;
					do {
						printf ("\n=================== ADMIN MENU ===================\n\n");
						printf ("1. SEARCH BY BRAND\n\n");
						printf ("2. SEARCH BY RENTAL ID\n\n");
						printf ("3. SEARCH BY CAR ID\n\n");
						printf ("4. UPDATE RENTAL CAR\n\n");
						printf ("5. SORT BY BRAND\n\n");
						printf ("6. CHECK MAINTENANCE\n\n");
						printf ("7. REVENUE REPORT\n\n");
						printf ("8. DISPLAY LIST OF RENTAL CAR\n\n");
						printf("\n----------------------------------------------------\n");
						printf ("0. EXIT\n\n");
						scanf ("%d", &serverChoice);
						system("cls");
						switch (serverChoice) {
							case 0:
								system("cls");
								break;
							case 1: {
								// SEARCH BY BRAND
								system("cls");
								printf("\n---------------------------------------- |(0)-(0)| ----------------------------------------\n\n");
								printf ("1. SEARCH A CAR BY BRAND. |(0)-(0)|\n\n");
								printf ("0. BACK TO MENU\n\n");
								printf ("INPUT YOUR CHOICE: ");
								int searchBrandChoice;
								scanf ("%d", &searchBrandChoice);
								if (searchBrandChoice==1) {
									system ("cls");
									searchByBrand (listCar, carCount);
								}
								break;
							}
							
							case 2: {
								// Search by rental ID
								system("cls");
								printf("\n---------------------------------------- |(0)-(0)| ----------------------------------------\n\n");
								printf ("1. SEARCH A CAR BY RENTAL ID. |(0)-(0)|\n\n");
								printf ("0. BACK TO MENU\n\n");
								printf ("INPUT YOUR CHOICE: ");
								int searchRentalIDChoice;
								scanf ("%d", &searchRentalIDChoice);
								if (searchRentalIDChoice==1) {
									system ("cls");
									searchByRentalID (rentalsList, rentalCount);
								}
								break;
							}
							
							case 3: {
								// Search by car ID
								system("cls");
								printf("\n---------------------------------------- |(0)-(0)| ----------------------------------------\n\n");
								printf ("1. SEARCH A CAR BY CAR ID. |(0)-(0)|\n\n");
								printf ("0. BACK TO MENU\n\n");
								printf ("INPUT YOUR CHOICE: ");
								int searchCarIDChoice;
								scanf ("%d", &searchCarIDChoice);
								if (searchCarIDChoice==1) {
									system ("cls");
									searchByCarID (listCar, carCount);
								}
								break;
							} 

							case 4: { // Update rental car
								int updateRentalCarChoice;
								do {
									system("cls");
									printf ("\n=================== UPDATE RENTAL CAR ===================\n\n");
									printf ("1. ADD CAR\n\n");
									printf ("2. REMOVE CAR\n\n");
									printf ("3. UPDATE RENTAL RATE\n\n");
									printf("\n----------------------------------------------------\n");
									printf ("0. EXIT\n\n");
									scanf ("%d", &updateRentalCarChoice);
									system("cls");
									switch (updateRentalCarChoice) {
										case 0:
											system("cls");
											break;
										case 1: {
											// Add car
											system("cls");
											printf("\n---------------------------------------- |(0)-(0)| ----------------------------------------\n\n");
											printf ("1. ADD A CAR TO INVENTORY. |(0)-(0)|\n\n");
											printf ("0. BACK TO MENU\n\n");
											printf ("INPUT YOUR CHOICE: ");
											int addCarChoice;
											scanf ("%d", &addCarChoice);
											if (addCarChoice==1) {
												system ("cls");
												addVehicles (listCar, &carCount);
											}
											break;
										}

										case 2: {
											// Remove car
											system("cls");
											printf("\n---------------------------------------- |(0)-(0)| ----------------------------------------\n\n");
											printf ("1. REMOVE A CAR TO INVENTORY. |(0)-(0)|\n\n");
											printf ("0. BACK TO MENU\n\n");
											printf ("INPUT YOUR CHOICE: ");
											int removeCarChoice;
											scanf ("%d", &removeCarChoice);
											if (removeCarChoice==1) {
												system ("cls");
												removeCar (listCar, &carCount);
											}
											break;
										}

										case 3: {
											//  Update rental rate
											system("cls");
											printf("\n---------------------------------------- |(0)-(0)| ----------------------------------------\n\n");
											printf ("1. UPDATE RENTAL RATE. |(0)-(0)|\n\n");
											printf ("0. BACK TO MENU\n\n");
											printf ("INPUT YOUR CHOICE: ");
											int updateRentalRateChoice;
											scanf ("%d", &updateRentalRateChoice);
											if (updateRentalRateChoice==1) {
												system ("cls");
												updateRentalRate (listCar, carCount);
											}
											break;
										} 

										default:
											printf ("ERROR! YOUR CHOICE.\n");
											break;
									}
									if (updateRentalCarChoice!=0) {
										while (getchar()!='\n');
										getchar();
										system("cls");
									}									
								} while (updateRentalCarChoice!=0);
								break;
							}
								
							case 5: {
								// Sort by brand
								system("cls");
								printf("\n---------------------------------------- |(0)-(0)| ----------------------------------------\n\n");
								printf ("1. SORT CARS BY BRAND ORDER. |(0)-(0)|\n\n");
								printf ("0. BACK TO MENU\n\n");
								printf ("INPUT YOUR CHOICE: ");
								int sortByBrandChoice;
								scanf ("%d", &sortByBrandChoice);
								if (sortByBrandChoice==1) {
									system ("cls");
									sortByBrand (listCar, carCount);
								}
								break;
							}

							case 6: {
								// Check maintenance
								system("cls");
								printf("\n---------------------------------------- |(0)-(0)| ----------------------------------------\n\n");
								printf ("1. CHECK MAINTENANCE OF RENTAL CARS. |(0)-(0)|\n\n");
								printf ("0. BACK TO MENU\n\n");
								printf ("INPUT YOUR CHOICE: ");
								int checkMaintenanceChoice;
								scanf ("%d", &checkMaintenanceChoice);
								if (checkMaintenanceChoice==1) {
									system ("cls");
									checkMaintenance (listCar, carCount);
								}
								break;
							} 
							
							case 7: {
								// Revenue report
								system("cls");
								printf("\n---------------------------------------- |(0)-(0)| ----------------------------------------\n\n");
								printf ("1. REVENUE REPORT OF RENTAL CARS. |(0)-(0)|\n\n");
								printf ("0. BACK TO MENU\n\n");
								printf ("INPUT YOUR CHOICE: ");
								int revenueReportChoice;
								scanf ("%d", &revenueReportChoice);
								if (revenueReportChoice==1) {
									system ("cls");
									revenueReport (rentalsList, rentalCount);
								}
								break;
							} 

							case 8: {
								// Display list of rental cars
								system("cls");
								printf("\n---------------------------------------- |(0)-(0)| ----------------------------------------\n\n");
								printf ("1. SHOW LIST OF RENTAL CARS. |(0)-(0)|\n\n");
								printf ("0. BACK TO MENU\n\n");
								printf ("INPUT YOUR CHOICE: ");
								int rentalCarListChoice;
								scanf ("%d", &rentalCarListChoice);
								if (rentalCarListChoice==1) {
									system ("cls");
									displayRentalCarList (listCar, carCount);
								}
								break;
							}

							default:
								printf ("ERROR! YOUR CHOICE ^^\"\n");
						}
						if (serverChoice!=0) {
							while (getchar()!='\n');
							getchar();
							system("cls");
						}						
					} while (serverChoice!=0);
					
				}
				else {
					printf ("TOO MANY FAILED ATTEMPTS! BACK TO MAIN MENU.");
				}
			
				break;
			}
			case 0: // Menu to exit
				printf ("GOOD BY SEE YOU LATER \"||(0)-(0)||\" ^_^\n\n\n");
				saveCar (listCar, carCount);
				saveRental (rentalsList, rentalCount);
				break;
			default:
				printf ("ERROR! YOUR CHOICE ^^! TRY AGAIN\n");
				// quay lại menu chính và nhập lại
				
		}
		if (choice!=0) {
			while (getchar()!='\n');
			getchar();
			system("cls");
		}
		
	} while (choice!=0);
	
	
	return 0;
}