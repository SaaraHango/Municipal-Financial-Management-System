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
    printf("1. Enter Budget Data\n");
    printf("2. Display All Department budgets: \n")
// theres an error i cant clear here
    printf("3. View Over-Budget Departments:\n");
    printf("4. Exit\n");
    printf("Enter your choice from (1-4): ");

    if (scanf("%d", &choice) !=1){
        //Thsi will clear invalid output
        while (getchar() != '\n');
        printf("Invalid selection. Kindly enter a valid number. \n");
        continue;
    }

    // new line character left by scanf
    getchar();

        switch (choice) {

            case 1:
                enterBudgetData(departments, &count);
                // automatically reclculate remaining budgets and status after entering
                calculateBudgets(departments, count);
                break;

            case 2:
                displayBudgetInformation(departments, count);
                break;

            case 3:
                displayStatus(departments, count);
                break;

            case 4:
                printf("\nExiting Budget Management System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid selection. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

// we need to enter departmental name, allocated budget anf expenditure
void enterBudgetData(Department depts[], int count){
    //the * is a pointer
    // perhaps the pointer needs a int data type
    if (*count >= MAX_DEPARTMENTS){
        printf("\nMaximum department Limit (%d) reached.\n", MAX_DEPARTMENTS);

        return;
    }
    
}