#ifdef SUPPLIERS_H
#define SUPPLIRES_H

#define MAX_SUPPLIERS 100

typedef struc {
    int supplierID
    char supplierName[100];
    char email[100];
    char telephone[30];
    char town[50];

} Supplier;

void addSupplier(Supplier suppliers[], int *supplierCount);
void displaySuppliers(Supplier suppliers[], int supplierCount);
void searchSuppliers(Supplier suppliers[], int supplierCount);
void compareSupplier(Supplier suppliers[], int supplierCount);

#endif
