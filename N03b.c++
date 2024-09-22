#include <iostream>
using namespace std;

int main() {
    // Define constants for unit costs and surcharge
    const double costFirst10 = 150.0;  // Cost per unit for the first 10 units
    const double costNext10 = 175.0;   // Cost per unit for the next 10 units (11-20)
    const double costAdditional = 200.0; // Cost per unit for units beyond 20
    const double surchargeRate = 0.15;  // 15% surcharge
    const double vatRate = 0.18;  // 18% VAT rate

    // Variables to hold user inputs
    double userBalance, totalCost = 0.0;
    int waterUnits;

    // Prompt user to input balance and water usage
    cout << "Enter the amount of money loaded on your account (UGX): ";
    cin >> userBalance;
    cout << "Enter the number of water units consumed: ";
    cin >> waterUnits;

    // Calculate the total cost based on the number of units consumed
    if (waterUnits <= 10) {
        totalCost = waterUnits * costFirst10;
    } 
    else if (waterUnits <= 20) {
        totalCost = 10 * costFirst10 + (waterUnits - 10) * costNext10;
    } 
    else {
        totalCost = 10 * costFirst10 + 10 * costNext10 + (waterUnits - 20) * costAdditional;
    }

    // Apply 15% surcharge
    totalCost += totalCost * surchargeRate;

    // Add 18% VAT
    totalCost += totalCost * vatRate;

    // Check if the user's balance is sufficient
    if (userBalance >= totalCost) {
        // Calculate remaining balance
        double remainingBalance = userBalance - totalCost;
        cout << "Transaction successful!" << endl;
        cout << "Total cost (including surcharge and VAT): " << totalCost << " UGX" << endl;
        cout << "Remaining balance: " << remainingBalance << " UGX" << endl;
    } else {
        // Output error message if insufficient balance
        cout << "Error: Insufficient balance!" << endl;
        cout << "Total cost (including surcharge and VAT): " << totalCost << " UGX" << endl;
        cout << "Your balance: " << userBalance << " UGX" << endl;
    }

    return 0;
}
