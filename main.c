//================ Declare library =================== 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//================ Declare files ===================  
#include "ConsoleIO.h"
#include "FileHelper.h"
#include "Rental.h"
#include "Search.h"
#include "Vehicle.h"
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
	printf ("========== Welcome to RC-NHD Shop ==========\n");
	printf ("\t\t||(0)-(0)||\n\n");
	int choice;
	
	do {
		
		printf("^^ Click Your Choice ^^\n");
		printf ("1. Customer\n");
		printf ("2. Server\n");
		printf ("0. Exit\n\n");
		scanf ("%d", &choice);
		system ("cls");
		switch (choice) {
			case 1: {
				int customerChoice;
				do {
					printf ("1. DISPLAY LIST OF RENTAL CAR\n");
						
					printf ("2. RETURN CAR\n");
						
					printf ("3. FILTER BY PRICE\n");
						
					printf ("4. SEARCH BY RENTAL ID\n");
						
					printf ("5. SEARCH BY BRAND\n");
						
					printf ("6. DISPLAY DISCOUNT TABLE\n");
						
					printf ("0. EXIT\n\n");
						
						
					scanf ("%d", &customerChoice);
					// loop customer choice
					switch (customerChoice) {
						case 0:
							system("cls");
							// display thoát Menu Customer trở về Menu chính
							break;
						case 1:
							// gọi hàm hiển thị bảng danh danh ô tô kèm các thông tin của mỗi chiếc ô tô (Car Name, Year, Status,...)
							// gọi hàm gán ô tô assignCar nếu khách hàng muốn thuê xe
							// goi các hàm tính tính tiền cho khách hàng
							break;
						case 2:
							// gọi hàm trả về ô tô cho cửa hàng
							break;
						case 3:
							// gọi hàm lọc giá để hiển thị xe thuê phù hợp với tài chính của khách hàng
							break;
						case 4:
							// gọi hàm tìm kiếm bằng Rental ID
							break;
						case 5:
							// gọi hàm tìm kiếm theo hãng
							break;
						case 6:
							// gọi hàm hiển thị bảng thông tin về khuyến mãi cho khách hàng xem
							break;
						default:
							printf ("Error! choose again.\n");
					}
				
					
				} while (customerChoice!=0);
				
				break;
			}
			case 2: {
				
				char password[15];
				int tries=0;
				do {
					printf ("REQUIRE INPUT PASSWORD: ");
					scanf ("%s", password);
					tries++;
					if (strcmp(password, serverPASSWORD)!=0) {
						printf ("ERROR PASSWORD!");
						system("pause"); // nếu muốn dùng getchar thì phải xóa đi buffer 
					}
						
					system("cls");
				} while ((strcmp(password, serverPASSWORD)!=0) && tries<3);
				system("cls");
				if (strcmp(password, serverPASSWORD)==0) {
					int serverChoice;
					do {
						printf ("1. SEARCH BY BRAND\n");
						printf ("2. SEARCH BY RENTAL ID\n");
						printf ("3. SEARCH BY CAR ID\n");
						printf ("4. UPDATE RENTAL CAR\n");
						printf ("5. SORT BY BRAND\n");
						printf ("6. CHECK MAINTENANCE\n");
						printf ("7. REVENUE REPORT\n");
						printf ("8. DISPLAY LIST OF RENTAL CAR\n");
						printf ("0. EXIT\n\n");
						scanf ("%d", &serverChoice);
						system("cls");
						switch (serverChoice) {
							case 0:
								system("cls");
								printf ("CANCEL\n");
								break;
							case 1:
							case 2:
							case 3:
							case 4: {
								int updateRentalCarChoice;
								do {
									system("cls");
									printf ("1. ADD CAR\n");
									printf ("2. REMOVE CAR\n");
									printf ("3. UPDATE RENTAL RATE\n");
									printf ("0. EXIT\n");
									scanf ("%d", &updateRentalCarChoice);
									system("cls");
									switch (updateRentalCarChoice) {
										case 0:
											break;
										case 1:
											addVehicles (listCar, &carCount);
											break;
										case 2:
											removeCar (listCar, &carCount);
											break;
										case 3:
											updateRentalRate (listCar, carCount);
											break;
										default:
											printf ("ERROR! YOUR CHOICE.\n");
											break;
									}
									
								} while (updateRentalCarChoice!=0);
								break;
							}
								
								// 1. gọi hàm addCar
								// 2. gọi hàm removeCar
								// 3. gọi hàm updateRentalRate
								// 4. gọi hàm exit trở về Menu Update renal car
								// cho phép Admin lựa chọn và làm việc
							case 5:
							case 6:
							case 7:
							case 8:
							default:
								printf ("ERROR! YOUR CHOICE ^^\"\n");
						}
					} while (serverChoice!=0);
					
				}
				else {
					printf ("NOT TRUE!:{\n\n");
				}
				break;
			}
			case 0:
				printf ("GOOD BY SEE YOU LATER \"||(0)-(0)||\" ^_^\n");
				// saveCars(listCar, carCount);
				// saveRentals(rentalsList, rentalCount);
				// nhấn nút enter và thoát khỏi chương trình
				break;
			default:
				printf ("ERROR! YOUR CHOICE ^^! TRY AGAIN\n");
				// quay lại menu chính và nhập lại
				
		}
		
	} while (choice!=0);
	
	
	
	return 0;
}