#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

void employeeReport(){
  printf("\n--- EMPLOYEE REPORT ---\n");
    printf("Total Employees: %d\n", employeeCount);
    for (int i = 0; i < employeeCount; i++) {
        displayEmployeeDetails(employees[i]); 
  }
}

void budgetReport(){float budget, expenditure;
    enterBudget(&budget, &expenditure);
    printf("Remaining: N$%.2f\n", calculateRemaining(budget, expenditure));
    checkBudgetStatus(budget, expenditure);
}

void supplierReport(){
  printf("\n--- SUPPLIER REPORT ---\n");
    printf("Feature under development by teammate.\n");
}
void assetReport(){
   extern Asset assets[MAX_ASSETS];
    extern int assetCount;
    assetReport(assets, assetCount);
}
void reportMenu(){
 int choice;
    do {
        printf("\n===== REPORTS MENU =====\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: employeeReport(); break;
            case 2: budgetReport(); break;
            case 3: supplierReport(); break;
            case 4: assetReportSummary(); break;
            case 5: return;
            default: printf("Invalid choice!\n");
        }
    } while(1);
  
}
