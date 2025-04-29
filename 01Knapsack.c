
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int* weights = (int*)malloc(n * sizeof(int));
    int* values = (int*)malloc(n * sizeof(int));

    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int maxValue = 0;
    int subsetCount = 1 << n; // 2^n subsets

    for (int subset = 0; subset < subsetCount; subset++) {
        int totalWeight = 0;
        int totalValue = 0;
        for (int i = 0; i < n; i++) {
            if (subset & (1 << i)) {
                totalWeight += weights[i];
                totalValue += values[i];
            }
        }
        if (totalWeight <= capacity && totalValue > maxValue) {
            maxValue = totalValue;
        }
    }

    printf("Maximum value possible: %d\n", maxValue);

    free(weights);
    free(values);

    return 0;
}

/*
Sample Input:
Enter the number of items: 3
Enter the weights of the items: 10 20 30
Enter the values of the items: 60 100 120
Enter the capacity of the knapsack: 50

Output:
Maximum value possible: 220
*/
