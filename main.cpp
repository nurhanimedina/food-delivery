#include <iostream>
using namespace std;

int main() {

    double food_prices, quantity;
    double delivery_distance;
    string delivery_method;
    double voucher, service_fee;
    double rate_per_km = 2.0;     // contoh kadar per km
    double express_fee = 5.0;     // contoh caj express
    double time_per_km = 3.0;     // contoh masa per km (minit)

    cout << "Enter food price: ";
    cin >> food_prices;
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter delivery distance (km): ";
    cin >> delivery_distance;
    cout << "Enter delivery method (Standard/Express): ";
    cin >> delivery_method;
    cout << "Enter voucher amount: ";
    cin >> voucher;
    cout << "Enter service fee: ";
    cin >> service_fee;

    // PROCESS
    double food_subtotal = food_prices * quantity;
    double delivery_charge;

    if (delivery_method == "Standard") {
        delivery_charge = delivery_distance * rate_per_km;
    } else if (delivery_method == "Express") {
        delivery_charge = (delivery_distance * rate_per_km) + express_fee;
    } else {
        delivery_charge = 0; // fallback jika method salah
    }

    double subtotal_after_discount = food_subtotal - voucher;
    double total_payment = subtotal_after_discount + delivery_charge + service_fee;
    double estimated_time = 15 + (delivery_distance * time_per_km);

    // OUTPUT
    cout << "\nFood Subtotal: RM" << food_subtotal;
    cout << "\nDelivery Charge: RM" << delivery_charge;
    cout << "\nTotal Payment: RM" << total_payment;
    cout << "\nEstimated Delivery Time: " << estimated_time << " minutes\n";

    return 0;
}
