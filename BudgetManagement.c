#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPARTMENTS 50
#define MAX_NAME_LENGTH 50

//A way to join several variables in one place; in this case DEPARTMENT
typedef struct{
    char nameDepartment[MAX_NAME_LENGTH];
    double allocatedBudget;
    double expenditure;
    double remainingBudget;
    int status;
} Department;

void enterBudgetData(Department depts[], int *count);
void calculateBudgets(Department depts[],int count);
void displayBudgetInformation(Department depts[], int count);
void displayStatus(Department depts[], int count);
int main(){
Department departments[MAX_DEPARMENTS];
int count = 0;
int choice;

do{
    printf("\n====================MUNICIPAL BUDGET MANAGEMENT SYSTEM==========================\n");
    printf("1. Enter budget data\n";)
}
    return 0;
}