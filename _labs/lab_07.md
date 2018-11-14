---
layout: page
title: Cvičenie 7 a 8
category: lab
---

## OpenMP

V pripravenom prostredí pre Windows je OenmpMP funkčné. Mac OS X neobsahuje clang s podporou openmp, je potrebné si podporu doinštalovať, napríklad takýmto spôsobom ( https://iscinumpy.gitlab.io/post/omp-on-high-sierra/), čiže:

0. Potrebné mať nainštalované homebrew (http://brew.sh):
```
$ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

0. Potom nainštalovať openmp knižnicu pre clang:
```
$ brew install libomp
```

0. Kompilácia prebieha potom takto:
```
$ gcc -Xpreprocessor -fopenmp -lomp omp_fib.c -o omp_fib
```



## Príklady

Pozrite si materiály z prednášky a príklady v **PaPP/examples/openmp**. Precvičte si základné konštrukcie na vytváranie paralelnej oblasti (`#pragma omp parallel`) a základné konštrukcie na deľbu práce (`#pragma omp for`, `#pragma omp sections`, `#pragma omp single`). Pre direktívu `#pragma omp for` si pozrite a vyskúšajte rôzne spôsoby plánovania iterácií cyklu na vykonanie (klauzula `schedule()`). Pozrite si konštrukcie na definovanie rozsahu platnosti údajov ( `private`,`shared` ,`firstprivate` ,`lastprivate` ,... ).

## Úloha
Pozrite si implementáciu výpočtu n-tého prvku Fibonacciho postupnosti za použitia OpenMP ([omp_fib.c](labs/omp_fib.c)). Použite OpenMP pre paralelizáciu rekurzívnej verzie algoritmu quicksort ([qs.c](labs/qs.c)).
