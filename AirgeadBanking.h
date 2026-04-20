#pragma once
#ifndef AIRGEADBANKING_H
#define AIRGEADBANKING_H

class AirgeadBanking {
private:
    // Save the initial investment amount provided by the user.
    double m_initialInvestment;

    // Save the user's monthly deposit amount.
    double m_monthlyDeposit;

    // Save the user's yearly interatest rate.
    double m_annualInterest;

    // Record the investment duration in years.
    int m_numberOfYears;

public:
    // Constructor.
    AirgeadBanking();

    // Stores input inside the class
    void SetInitialInvestment(double initialInvestment);
    void SetMonthlyDeposit(double monthlyDeposit);
    void SetAnnualInterest(double annualInterest);
    void SetNumberOfYears(int numberOfYears);

    // Return stored values if needed.
    double GetInitialInvestment() const;
    double GetMonthlyDeposit() const;
    double GetAnnualInterest() const;
    int GetNumberOfYears() const;

    // Print a single row of the yearly results.
    void PrintDetails(int year, double yearEndBalance, double interestEarned) const;

    // Displays report
    void DisplayWithoutMonthlyDeposit() const;
    void DisplayWithMonthlyDeposit() const;
};

#endif