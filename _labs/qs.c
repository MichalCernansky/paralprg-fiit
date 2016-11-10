//
//  qs.c
//
//  Created by Michal Cernansky on 10/11/2016.
//  Copyright © 2016 Michal Cernansky. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int split(int a[], int low, int high);

void quicksort(int a[], int low, int high)
{
    int middle;
    
    if (low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high)
{
    int partelement = a[low];
    
    for (;;) {
        while (low < high && partelement <= a[high])
            high--;
        if (low >= high) break;
        a[low++] = a[high];
        
        while (low < high && a[low] <= partelement)
            low++;
        if (low >= high) break;
        a[high--] = a[low];
    }
    
    a[high] = partelement;
    return high;
}

#define N 100000000

int a[N];

int main (int argc, char *argv[])
{
    srand((unsigned int)time(NULL));
    for (int i=0;i<N;i++) a[i] = rand();
    
    quicksort(a, 0, N-1);
    
    for (int i=0;i<10;i++) printf("a[%d] = %d\n", i, a[i]);
    for (int i=N-10;i<N;i++) printf("a[%d] = %d\n", i, a[i]);
}
