#ifndef BUDGET_H
#define BUDGET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPARTMENTS 50
#define MAX_NAME_LENGTH 50

// Structure to store departmental budget data
typedef struct {
    char nameDepartment[MAX_NAME_LENGTH];
    double allocatedBudget;
    double expenditure;
    double remainingBudget;
    int status; // 1 = WITHIN BUDGET, 0 = EXCEEDED BUDGET
} Department;

// Function Prototypes
void enterBudgetData(Department depts[], int *count);
void calculateBudgets(Department depts[], int count);
void displayBudgetInformation(Department depts[], int count);
void displayStatus(Department depts[], int count);

#endif // BUDGET_H
