//
//  fib.c
//
//  Created by Michal Cernansky on 07/11/2016.
//  Copyright © 2016 Michal Cernansky. All rights reserved.
//

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int fib_r(int n)
{
    if (n <= 1) return n;
    return fib_r(n-1)+fib_r(n-2);
}

int fib(int n)
{
    if (n <= 1) return n;
    if (n < 20) return fib_r(n-1)+fib_r(n-2);
    
    int f1, f2;
    
    #pragma omp task shared(f1) firstprivate(n)
    f1 = fib(n-1);

    #pragma omp task shared(f2) firstprivate(n)
    f2 = fib(n-2);

    #pragma omp taskwait
    return f1 + f2;
}

int main (int argc, char *argv[])
{
    
    int n = 40;
    int f;
    
    double t1 = omp_get_wtime();

    #pragma omp parallel shared(f) firstprivate(n)
    {
        #pragma omp single nowait
        f = fib(n);
    }

    double t2 = omp_get_wtime();
    
    printf("fib[%d] = %d (%.2lfs)\n", n, f, t2-t1);

    return 0;
}

