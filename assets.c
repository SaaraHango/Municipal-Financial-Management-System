#include <stdio.h>
#include <string.h>
#include "assets.h"

void addAsset(Asset assets[], int *count)
{
    if(*count >= MAX_ASSETS) {
        printf("Asset list is full.\n");
        return;
    }

    Asset newAsset;
    printf("Enter Asset ID: ");
        scanf("%d" , &newAsset.assetId);
        
        printf("Enter Asset Name: ");
        scanf(" %49[^\n]" , newAsset.name);
        
        printf("Enter Asset type: ");
        scanf(" %29[^\n]" ,newAsset.type);
        
        printf("Enter Purchase Value: ");
        scanf("%lf" , &newAsset.purchaseValue);
        
        if (newAsset.purchaseValue < 0){
            printf("Purchase value cannot be negative. Asset not added.\n");
            return;
        }

        printf("Enter Department: ");
        scanf(" %29[^\n]" , newAsset.department);
        
        printf("Enter Condition (e.g. New, Good, Fair, Poor): ");
        scanf(" %19[^\n]", newAsset.condition);

        assets[*count] =newAsset;
    (*count)++;
printf("Asset added successfully. \n");
}

void displayAssets(const Asset assets[], int count)
{
    if(count == 0) {
        printf("No assets registered. \n");
        return;
    }
        printf("\n--- ASSET REGISTER ---\n");
        for (int i=0;i<count;i++){
        printf("ID: %d | Name: %s | Type: %s | Value: N$%.2f | Dept: %s | Condition: %s\n",assets[i].assetId, assets[i].name, assets[i].type,assets[i].purchaseValue, assets[i].department,assets[i].condition);
    }
    }
    
    void searchAsset(const Asset assets[], int count)
    {
    int searchId;
    printf("Enter Asset ID to search: ");
    scanf("%d" , &searchId);
    
    for (int i=0;i<count;i++) {
    if (assets[i].assetId==searchId) {
    printf("Found: %s (%s),Value: N$%.2f, Dept: %s, Condition: %s\n",assets[i].name,assets[i].type,assets[i].purchaseValue,assets[i].department,assets[i].condition);
    return;
    }
    }
    printf("Asset with ID %d not found. \n" , searchId);
    }
    void assetReport(const Asset assets[], int count)
    {
    double totalValue =0;
    printf("\n--- ASSET REPORT ---\n");
    printf("Total Assets: %d\n", count);
    
    for (int i=0;i<count; i++){
    totalValue += assets[i].purchaseValue;
    }
    printf("Total Asset Value : N$%.2f\n", totalValue);
    }


            

        
    
