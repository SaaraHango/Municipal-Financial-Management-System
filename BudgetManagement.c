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
        printf("\nMaximum department limit (%d) reached.\n", MAX_DEPARTMENTS);
        return;
    }

}

printf("\n---Enter Department Details---\n");
    printf("Department Name: ");
    fgets (depts[*count].nameDepartment, MAX_NAME_LENGTH, stdin);
    // remove the trailing newline character from fgets
    depts[*count].nameDepartment[strcspn(depts[*count].nameDepartment, "\n")] = '\0';

    printf("Allocated Budget (N$): ");
    while (scanf("%lf", &depts[*count].allocatedBudget) != 1 || depts[*count].allocatedBudget < 0) {
        while (getchar() != '\n');
        printf("Invalid input. Enter a valid positive budget amount (N$): ");
    }

    printf("Expenditure (N$): ");
    while (scanf("%lf", &depts[*count].expenditure) != 1 || depts[*count].expenditure < 0) {
        while (getchar() != '\n');
        printf("Invalid input. Enter a valid positive expenditure amount (N$): ");
    }

    (*count)++;
    printf("Department budget successfully added!\n");
}
(*count)++;
    printf("Department budget successfully added!\n");
}

// perform budget calculations and status 
void calculateBudgets(Department depts[], int count) {
    for (int i = 0; i < count; i++) {
        // Calculate remaining budget
        depts[i].remainingBudget = depts[i].allocatedBudget - depts[i].expenditure;

        // Decision-making structure to set status
        if (depts[i].expenditure <= depts[i].allocatedBudget) {
            depts[i].status = 1; // Within budget
        } else {
            depts[i].status = 0; // Exceeded budget
        }
    }
}

// 3. Display budget information in the required format
void displayBudgetInformation(Department depts[], int count) {
    if (count == 0) {
        printf("\nNo budget data available to display.\n");
        return;
    }

    printf("\n================ MUNICIPAL BUDGET REPORT ================\n");
    for (int i = 0; i < count; i++) {
        printf("Department:       %s\n", depts[i].nameDepartment);
        printf("Allocated Budget: N$%.2f\n", depts[i].allocatedBudget);
        printf("Expenditure:      N$%.2f\n", depts[i].expenditure);
        printf("Remaining Budget: N$%.2f\n", depts[i].remainingBudget);
        printf("Status:           %s\n", depts[i].status == 1 ? "WITHIN BUDGET" : "EXCEEDED BUDGET");
        printf("---------------------------------------------------------\n");
    }
}

// 4. Identify and display departments that exceeded their allocated budget
void displayStatus(Department depts[], int count) {
    if (count == 0) {
        printf("\nNo budget data available.\n");
        return;
    }

    int overBudgetCount = 0;
    printf("\n================ DEPARTMENTS EXCEEDING BUDGET ================\n");

    for (int i = 0; i < count; i++) {
        // Filter using status flag
        if (depts[i].status == 0) {
            overBudgetCount++;
            double deficit = depts[i].expenditure - depts[i].allocatedBudget;
            printf("Department:       %s\n", depts[i].nameDepartment);
            printf("Allocated Budget: N$%.2f\n", depts[i].allocatedBudget);
            printf("Expenditure:      N$%.2f\n", depts[i].expenditure);
            printf("Overspent Amount: N$%.2f\n", deficit);
            printf("Status:           EXCEEDED BUDGET\n");
            printf("--------------------------------------------------------------\n");
        }
    }

    if (overBudgetCount == 0) {
        printf("All departments are operating WITHIN their allocated budgets.\n");
    }
}