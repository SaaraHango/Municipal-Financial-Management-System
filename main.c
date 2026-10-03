#include <stdio.h>
#include "employees.h"

int main() {
    int choice;
    do {
        printf("\n========================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: employeeMenu(); break;
            case 6: printf("Exiting MFMS... Goodbye!\n"); break;
            default: printf("Module not yet implemented by teammate.\n");
        }
    } while(choice!= 6);
    return 0;
}
