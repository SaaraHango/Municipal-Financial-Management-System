#include <stdio.h>
#include "budget.h"

void enterBudget(float *budget, float *expenditure)
{
    printf("Enter departmental budget: ");
    scanf("%f", budget);

    printf("Enter expenditure: ");
    scanf("%f", expenditure);
}

float calculateRemaining(float budget, float expenditure)
{
    return budget - expenditure;
}

void checkBudgetStatus(float budget, float expenditure)
{
    float remaining = calculateRemaining(budget, expenditure);

    if (remaining > 0)
    {
        printf("Budget status: Within budget\n");
    }
    else if (remaining == 0)
    {
        printf("Budget status: Budget fully used\n");
    }
    else
    {
        printf("Budget status: Over budget\n");
    }
