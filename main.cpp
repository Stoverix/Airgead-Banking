#include <iostream>
#include <limits>
#include "AirgeadBanking.h"

using namespace std;

// Get a valid number from the user.
double GetValidDouble(string prompt) {
    double value;

    // Keep asking until you get a valid response
    while (true) {
        // Show message
        cout << prompt;

        // Read what the user input
        cin >> value;

        // Check that input is a number
        if (!cin.fail() && value >= 0) {
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        
        cout << "Invalid input. Please enter a non-negative number." << endl;

        
        cin.clear();

        // Remove bad input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Prompt user to enter valid number
int GetValidInt(string prompt) {
    int value;

    // Keep asking until you get a valid response.
    while (true) {
        // Show message.
        cout << prompt;

        
        cin >> value;

        // Check that input is a whole number 
        if (!cin.fail() && value > 0) {
            // Clear line before returning.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        // Tell user the input provided was invalid
        cout << "Invalid input. Please enter a whole number greater than 0." << endl;

        // Clear error state
        cin.clear();

        // Remove bad input.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    
    AirgeadBanking bankApp;

    // Show the input section
    cout << "**********************************" << endl;
    cout << "********** Data Input ************" << endl;

    // Obtains and stores the data
    double initialInvestment = GetValidDouble("Initial Investment Amount: ");
    double monthlyDeposit = GetValidDouble("Monthly Deposit: ");
    double annualInterest = GetValidDouble("Annual Interest (%): ");
    int numberOfYears = GetValidInt("Number of Years: ");

    bankApp.SetInitialInvestment(initialInvestment);
    bankApp.SetMonthlyDeposit(monthlyDeposit);
    bankApp.SetAnnualInterest(annualInterest);
    bankApp.SetNumberOfYears(numberOfYears);

    
    cout << endl;
    cout << "Press Enter to continue..." << endl;
    cin.get();

    // Displays report excluding monthly deposits
    bankApp.DisplayWithoutMonthlyDeposit();

    // Display the report of month deposits.
    bankApp.DisplayWithMonthlyDeposit();

    
    return 0;
}