#include <iostream>
#include <iomanip>
using namespace std ;

void voucherValidity(string &status, double &voucher) ;
void method(string &m, double &d, double &charge) ;

int main() {

    //INPUT
    int choice ;
    int quantity ;
    double A = 8, B = 10, C = 12 ;
    double totalA, totalB, totalC, subtotal ;
    double delivery_distance, delivery_charge ;
    string delivery_method, student_status ;
    double voucher, service_fee = 2 ;
    double estimated_time, time_per_km = 3.0 ;    

	//PROCESS
	cout << "============================================================" << endl ;
	cout << "              Welcome to Hani's Restaurant"  << endl ;
	cout << "============================================================" << endl ;
	do{
		cout << "\nList of Menus that we offer for takeout" << endl ;
		cout << "1. Set A [Nasi Ayam] (Ala carte) - RM8.00" << endl ;
		cout << "2. Set B [Nasi Ayam + Teh Ais] - RM10.00" << endl ;
		cout << "3. Set C [Nasi Ayam + Mushroom + Telur + Teh Ais] - RM12.00" << endl ;
		cout << "4. Calculate food price" << endl ;
		cout << "Enter your choice (1/2/3/4) :" ;
		cin >> choice ;
		
		switch(choice){
			case 1 :
				cout << "Enter quantity: " ;
				cin >> quantity ; ;
				totalA = totalA + (quantity * A) ;
				cout << fixed << setprecision(2) << "Total price for " << quantity << " Set A is RM" << totalA << endl ;
				break ;
			case 2 :
				cout << "Enter quantity: " ;
				cin >> quantity ;
				totalB = totalB + (quantity * B) ;
				cout << fixed << setprecision(2) << "Total price for " << quantity << " Set B is RM" << totalB << endl ;
				break ;
			case 3 :
				cout << "Enter quantity: " ;
				cin >> quantity ;
				totalC = totalC + (quantity * C) ;
				cout << fixed << setprecision(2) << "Total price for " << quantity << " Set C is RM" << totalC << endl ;
				break ;
			case 4 : 
				subtotal = totalA + totalB + totalC ;
				cout << fixed << setprecision(2) << "Food subtotal is RM" << subtotal << endl ;
				break ;
		}
	}while (choice != 4) ;
	
    cout << "Enter delivery distance (km): " ;
    cin >> delivery_distance ;
    
	voucherValidity(student_status, voucher) ;
    method(delivery_method, delivery_distance, delivery_charge) ;

    double subtotal_after_discount = subtotal * voucher ;
    double total_payment = subtotal_after_discount + delivery_charge + service_fee ;
    if (delivery_method == "Standard"){
    	estimated_time = 20 + (delivery_distance * time_per_km) ;
	}else if (delivery_method == "Express"){
		estimated_time = 10 + (delivery_distance * time_per_km) ; 
	}

    // OUTPUT
    cout << "\nSubtotal After Discount: RM" << subtotal_after_discount ;
    cout << "\nDelivery Charge: RM" << delivery_charge ;
    cout << "\nTotal Payment: RM" << total_payment ;
    cout << "\nEstimated Delivery Time: " << estimated_time << " minutes\n" ;

return 0;
}

void voucherValidity(string &status, double &voucher){
	do{
		cout << "Are you a student? (Y/N) :" ;
		cin >> status ;
		if (status == "Y"){
			voucher = 0.8 ;
			cout << "CONGRATS! You obtained a discount of 20%." << endl ;
		}else if (status == "N"){
			voucher = 1 ;
			cout << "SORRY! You do not get any discounts." << endl ;
		}else{
			cout << "INVALID CHOICE! PLEASE TRY AGAIN!" << endl ;
		}
	} while (status != "Y" && status != "N") ;
}

void method(string &m, double &d, double &charge){
	double r = 2.0 ;     
    double express_fee = 5.0 ;
    do{
    	cout << "Enter delivery method (Standard/Express): " ;
    	cin >> m ;
		if (m == "Standard") {
			charge = d * r ;
		} else if (m == "Express") {
			charge = (d * r) + express_fee ;
		} else {
			cout << "INVALID CHOICE! PLEASE TRY AGAIN!" << endl ;
		}
	}while (m != "Standard" && m != "Express") ;
}
