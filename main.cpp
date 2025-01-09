#include <bits/stdc++.h>

#define long long long

using namespace std;

// Function to get a valid integer input
int getValidInt(const char* prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1 || value < 0) {
        printf("Invalid input. Please enter a positive integer: ");
        while (getchar() != '\n'); // Clear the input buffer
    }
    return value;
}

// Function to get a valid Yes/No input
char getYesNoInput(const char* prompt) {
    char input;
    printf("%s", prompt);
    while (scanf(" %c", &input) != 1 || (input != 'Y' && input != 'N')) {
        printf("Invalid input. Please enter Y or N: ");
        while (getchar() != '\n'); // Clear the input buffer
    }
    return input;
}

int main() {
    printf("\n================================\n");
    printf("      Tax Calculator 2025       \n");
    printf("================================\n\n");

    char name[100];
    printf("Enter your name: ");
    scanf(" %s", name);

    long income = getValidInt("Enter your income: ");
    if (income < 240000) {
        printf("You do not have to pay tax\n");
        return 0;
    }

    income -= 60000; // Standard deduction for the taxpayer

    char input = getYesNoInput("Is your spouse a taxpayer (Y/N): ");
    if (input == 'N') income -= 60000;

    int children = getValidInt("How many children do you have: ");
    if (children > 0) {
        for (int i = 1; i <= children; i++) {
            printf("Enter the birth year of child %d: ", i);
            int year;
            while (scanf("%d", &year) != 1 || year < 0) {
                printf("Invalid input. Please enter a valid year: ");
                while (getchar() != '\n'); // Clear the input buffer
            }

            if (i == 1) {
                income -= 30000; // First child deduction
                printf("Child %d deduction: 30,000 baht.\n", i);
            } else {
                if (year >= 2018) {
                    income -= 60000; // Additional deduction for second child born in 2018 or later
                    printf("Child %d deduction: 60,000 baht (born in 2018 or later).\n", i);
                } else {
                    income -= 30000; // Standard deduction for second child born before 2018
                    printf("Child %d deduction: 30,000 baht.\n", i);
                }
            }
        }
    }

    int socialSecurity = getValidInt("Enter your social security contribution: ");
    income -= min(socialSecurity, 9000);

    int lifeInsurance = getValidInt("Enter your life insurance premium (10+ years policy): ");
    int healthInsurance = getValidInt("Enter your health and accident insurance premium: ");
    int totalInsurance = min(lifeInsurance + min(healthInsurance, 25000), 100000);
    income -= totalInsurance;

    int parentHealthInsurance = getValidInt("Enter your parent's health insurance premium: ");
    income -= min(parentHealthInsurance, 15000);

    int socialEnterprise = getValidInt("Enter your investment in Social Enterprise: ");
    income -= min(socialEnterprise, 100000);

    int thaiESG = getValidInt("Enter your investment in Thai ESG funds: ");
    income -= min(thaiESG * 0.3, 300000.0);

    int rmf = getValidInt("Enter your investment in RMF: ");
    int ssf = getValidInt("Enter your investment in SSF: ");
    int pvd = getValidInt("Enter your contribution to PVD or private school teacher's fund: ");
    int governmentPension = getValidInt("Enter your contribution to the Government Pension Fund: ");
    int nationalSavings = getValidInt("Enter your contribution to the National Savings Fund: ");

    int retirementTotal = min(
        min(rmf + ssf, 500000) + pvd + governmentPension + nationalSavings,
        500000
    );
    income -= retirementTotal;

    int pensionInsurance = getValidInt("Enter your pension insurance premium: ");
    income -= min(pensionInsurance, 200000);

    printf("\n================================\n");
    printf("Your net income after deduction: %lld baht\n", max(income, 0ll));

    double tax;
    if (income <= 150000) tax = 0;
    else if (income <= 300000) tax = 0.05 * income;
    else if (income <= 500000) tax = 0.10 * income;
    else if (income <= 750000) tax = 0.15 * income;
    else if (income <= 1000000) tax = 0.20 * income;
    else if (income <= 2000000) tax = 0.25 * income;
    else if (income <= 5000000) tax = 0.30 * income;
    else tax = 0.35 * income;

    printf("Amount of tax you need to pay: %.3f baht\n", tax);
    printf("================================\n\n");

    printf("Thank you for using our service, Mr./Mrs. %s\n", name);

    return 0;
}
