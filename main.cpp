#include <iostream>
using namespace std ;

void method(string &m, double &d, double &charge) ;

int main() {

    //INPUT
    double food_prices, quantity ;
    double delivery_distance ;
    string delivery_method ;
    double voucher, service_fee ;
    double time_per_km = 3.0 ;    

    cout << "Enter food price: " ;
    cin >> food_prices ;
    cout << "Enter quantity: " ;
    cin >> quantity ;
    cout << "Enter delivery distance (km): " ;
    cin >> delivery_distance ;
    cout << "Enter delivery method (Standard/Express): " ;
    cin >> delivery_method ;
    cout << "Enter voucher amount: " ;
    cin >> voucher ;
    cout << "Enter service fee: " ;
    cin >> service_fee ;

    // PROCESS
    double food_subtotal = food_prices * quantity ;
    double delivery_charge ;
    
    method(delivery_method, delivery_distance, delivery_charge) ;

    double subtotal_after_discount = food_subtotal - voucher ;
    double total_payment = subtotal_after_discount + delivery_charge + service_fee ;
    double estimated_time = 15 + (delivery_distance * time_per_km) ;

    // OUTPUT
    cout << "\nFood Subtotal: RM" << food_subtotal ;
    cout << "\nDelivery Charge: RM" << delivery_charge ;
    cout << "\nTotal Payment: RM" << total_payment ;
    cout << "\nEstimated Delivery Time: " << estimated_time << " minutes\n" ;

    return 0;
}

void method(string &m, double &d, double &charge){
	double r = 2.0 ;     
    double fee = 5.0 ;
	if (m == "Standard") {
		charge = d * r ;
	} else if (m == "Express") {
		charge = (d * r) + fee ;
	} else {
		charge = 0 ; 
	}
}
