#include <iostream>
#include <iomanip>
#include "AirgeadBanking.h"

using namespace std;

// Default constructor initializes the starting values.
AirgeadBanking::AirgeadBanking() {
    m_initialInvestment = 0.0;
    m_monthlyDeposit = 0.0;
    m_annualInterest = 0.0;
    m_numberOfYears = 0.0;
}

// Record the initial investment amount.
void AirgeadBanking::SetInitialInvestment(double initialInvestment) {
    m_initialInvestment = initialInvestment;
}

// Records the monthly deposit amount.
void AirgeadBanking::SetMonthlyDeposit(double monthlyDeposit) {
    m_monthlyDeposit = monthlyDeposit;
}

// Stores the annual interest rate.
void AirgeadBanking::SetAnnualInterest(double annualInterest) {
    m_annualInterest = annualInterest;
}

// Records the number of years.
void AirgeadBanking::SetNumberOfYears(int numberOfYears) {
    m_numberOfYears = numberOfYears;
}

// Return the amount of the initial investment.
double AirgeadBanking::GetInitialInvestment() const {
    return m_initialInvestment;
}

// Return the amount of the monthly deposit.
double AirgeadBanking::GetMonthlyDeposit() const {
    return m_monthlyDeposit;
}

// Return the annual interest rate.
double AirgeadBanking::GetAnnualInterest() const {
    return m_annualInterest;
}

// Returns the number of years.
int AirgeadBanking::GetNumberOfYears() const {
    return m_numberOfYears;
}


void AirgeadBanking::PrintDetails(int year, double yearEndBalance, double interestEarned) const {
    // Force all monetary values to display with 2 decimal places.
    cout << fixed << setprecision(2);

    // Prints year, ending balance, and interest earned.
    cout << year << "\t\t" << yearEndBalance << "\t\t" << interestEarned << endl;
}


void AirgeadBanking::DisplayWithoutMonthlyDeposit() const {
    // Begins the balance with the initial investment amount.
    double balance = m_initialInvestment;

    // Convert the annual percentage rate to a monthly decimal rate.
    double monthlyRate = (m_annualInterest / 100.0) / 12.0;

    // Print the report's title and column headers.
    cout << endl;
    cout << "  Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "==========================================================" << endl;
    cout << "Year\t\tYear End Balance\tInterest Earned" << endl;

    // Loop through each year.
    for (int year = 1; year <= m_numberOfYears; year++) {
        // Reset the total annual interest at the beginning of each year.
        double yearlyInterest = 0.0;

        // Loop through 12 months
        for (int month = 1; month <= 12; month++) {
            // Calculate interest for one month
            double monthlyInterest = balance * monthlyRate;

            // Add the interest for that month to the existing balance.
            balance = balance + monthlyInterest;

            // Add that month's interest to the annual total.
            yearlyInterest = yearlyInterest + monthlyInterest;
        }

        // Print results for the current year.
        PrintDetails(year, balance, yearlyInterest);
    }
}

// Show the monthly deposit report.
void AirgeadBanking::DisplayWithMonthlyDeposit() const {
    // Begin the balance with the initial investment amount.
    double balance = m_initialInvestment;

    // Convert the annual percentage rate to a monthly decimal rate.
    double monthlyRate = (m_annualInterest / 100.0) / 12.0;

    // 
    cout << endl;
    cout << "  Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "======================================================" << endl;
    cout << "Year\t\tYear End Balance\tInterest Earned" << endl;

    // Loop each year.
    for (int year = 1; year <= m_numberOfYears; year++) {
        // Reset the total yearly interest at the beginning of each year.
        double yearlyInterest = 0.0;

        // Loop through all 12 months.
        for (int month = 1; month <= 12; month++) {
            // Calculate interest based on the present balance.
            double monthlyInterest = balance * monthlyRate;

            // Add the interest for the month to the balance first.
            balance = balance + monthlyInterest;

            // Add the monthly interest to the annual total.
            yearlyInterest = yearlyInterest + monthlyInterest;

            // Include the monthly deposit following the interest calculation.
            // This aligns with the project rule that this month's deposit
            // It does not accrue interest until the following month.
            balance = balance + m_monthlyDeposit;
        }

        // Prints results for the current year.
        PrintDetails(year, balance, yearlyInterest);
    }
}