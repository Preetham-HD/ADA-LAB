#include <stdio.h>
void knapsack(int n, int p[], int w[], int W)
{
    int used[n];
    for (int i = 0; i < n; ++i)
        used[i] = 0;
    int cur_w = W;
    float tot_v = 0.0;
    int i, maxi;
    while (cur_w > 0)
    {
        maxi = -1;
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) &&
                ((maxi == -1) || ((float)w[i] / p[i] > (float)w[maxi] / p[maxi])))
                maxi = i;
        used[maxi] = 1;
        if (w[maxi] <= cur_w)
        {
            cur_w -= w[maxi];
            tot_v += p[maxi];
            printf("Added object %d (%d, %d) completely in the bag. Space left: %d.\n", maxi + 1,
                   w[maxi], p[maxi], cur_w);
        }
        else
        {
            int taken = cur_w;
            cur_w = 0;
            tot_v += (float)taken / p[maxi] * p[maxi];
            printf("Added %d%% (%d, %d) of object %d in the bag.\n", (int)((float)taken / w[maxi] * 100), w[maxi], p[maxi], maxi + 1);
        }
    }
    printf("Filled the bag with objects worth %.2f.\n", tot_v);
}
int main()
{
    int n, W;
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    int p[n], w[n];
    printf("Enter the profits of the objects: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("Enter the weights of the objects: ");
    for (int i = 0; i < n; i++)
    {

            scanf("%d", &w[i]);
    }
    printf("Enter the maximum weight of the bag: ");
    scanf("%d", &W);
    knapsack(n, p, w, W);
    return 0;
}


// OUTPUT:
// Enter the number of objects: 7
// Enter the profits of the objects: 5 10 15 7 8 9 4
// Enter the weights of the objects: 1 3 5 4 1 3 2
// Enter the maximum weight of the bag: 15
// Added object 4 (4, 7) completely in the bag. Space left: 11.
// Added object 7 (2, 4) completely in the bag. Space left: 9.
// Added object 3 (5, 15) completely in the bag. Space left: 4.
// Added object 6 (3, 9) completely in the bag. Space left: 1.
// Added 33% (3, 10) of object 2 in the bag.
// Filled the bag with objects worth 36.00.
