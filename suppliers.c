#include <stdio.h>
#include <string.h>

#define VAT_RATE 0.15

void displayMenu(void);
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
void removeNewline(char *str);

int main() {
    int choice;

    int supplierID = 0;
    char supplierName[100] = "";
    char supplierEmail[100] = "";
    char supplierPhone[30] = "";
    char supplierTown[50] = "";
    int hasSupplier = 0;

    float amount, basic, housing, transport, revenue, expenses, result;
    char searchName[100];

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("\n--- Add Supplier ---\n");
                
                printf("Enter Supplier ID (e.g., 101): ");
                scanf("%d", &supplierID);
                getchar();

                printf("Enter Name: ");
                fgets(supplierName, sizeof(supplierName), stdin);
                removeNewline(supplierName);

                printf("Enter Email: ");
                fgets(supplierEmail, sizeof(supplierEmail), stdin);
                removeNewline(supplierEmail);

                printf("Enter Phone: ");
                fgets(supplierPhone, sizeof(supplierPhone), stdin);
                removeNewline(supplierPhone);

                printf("Enter Town: ");
                fgets(supplierTown, sizeof(supplierTown), stdin);
                removeNewline(supplierTown);

                hasSupplier = 1;
                printf("\nSupplier #%d added successfully!\n", supplierID);
                break;

            case 2:
                printf("\n--- Supplier Details ---\n");
                if (hasSupplier) {
                    printf("ID: %d\n", supplierID);
                    printf("Name: %s (Length: %d)\n", supplierName, (int)strlen(supplierName));
                    printf("Email: %s\n", supplierEmail);
                    printf("Phone: %s\n", supplierPhone);
                    printf("Town: %s\n", supplierTown);
                } else {
                    printf("No supplier records found!\n");
                }
                break;

            case 3:
                printf("\n--- Search Supplier ---\n");
                if (!hasSupplier) {
                    printf("No supplier record exists to search.\n");
                } else {
                    printf("Enter supplier name to search: ");
                    fgets(searchName, sizeof(searchName), stdin);
                    removeNewline(searchName);

                    if (strcmp(supplierName, searchName) == 0) {
                        printf("Match Found! ID #%d (%s) lives in %s.\n", supplierID, supplierName, supplierTown);
                    } else {
                        printf("No matching supplier found.\n");
                    }
                }
                break;

            case 4:
                printf("\n--- Calculate VAT ---\n");
                printf("Enter Invoice Amount: ");
                scanf("%f", &amount);
                result = calculateVAT(amount);
                printf("VAT Amount (15%%): $%.2f\n", result);
                break;

            case 5:
                printf("\n--- Calculate Gross Salary ---\n");
                printf("Enter Basic Pay: ");
                scanf("%f", &basic);
                printf("Enter Housing Allowance: ");
                scanf("%f", &housing);
                printf("Enter Transport Allowance: ");
                scanf("%f", &transport);
                result = calculateSalary(basic, housing, transport);
                printf("Gross Salary: $%.2f\n", result);
                break;

            case 6:
                printf("\n--- Calculate Budget Balance ---\n");
                printf("Enter Total Revenue: ");
                scanf("%f", &revenue);
                printf("Enter Total Expenses: ");
                scanf("%f", &expenses);
                result = calculateBudget(revenue, expenses);
                printf("Net Balance: $%.2f\n", result);

                if (result > 0) {
                    printf("Status: BUDGET SURPLUS\n");
                } else if (result < 0) {
                    printf("Status: BUDGET DEFICIT\n");
                } else {
                    printf("Status: BALANCED BUDGET\n");
                }
                break;

            case 7:
                printf("\nExiting Municipal Financial Management System. Goodbye!\n");
                break;

            default:
                printf("Invalid selection! Please choose between 1 and 7.\n");
        }
    } while (choice != 7);

    return 0;
}

void displayMenu(void) {
    printf("\n========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM \n");
    printf("========================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier Details\n");
    printf("3. Search Supplier\n");
    printf("4. Calculate VAT\n");
    printf("5. Calculate Gross Salary\n");
    printf("6. Calculate Budget Balance\n");
    printf("7. Exit\n");
    printf("--------------------------------------\n");
    printf("Enter choice (1-7): ");
}

float calculateVAT(float amount) {
    return amount * VAT_RATE;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
