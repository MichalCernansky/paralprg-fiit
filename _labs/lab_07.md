---
layout: page
title: Cvičenie 7 a 8
category: lab
---

## OpenMP

V pripravenom prostredí pre Windows je OenmpMP funkčné. Pre Mac OS X žial XCode neobsahuje clang s podporou openmp, je potrebné si to doinštalovať, napríklad takýmto spôsobom ( http://stackoverflow.com/a/33687414), čiže:
0. Potrebné nainštalovať homebrew (http://brew.sh)
```
$ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

0. Potom nainštalovať balíček pre podporu podporu openmp v clangu: brew install clang-omp
```
$ brew install homebrew/boneyard/clang-omp
```
0. A v projekte pre XCode ponastavovať nastavenia, resp. skúste tento projekt, kde je to už spravené:  [omp_hello.zip](labs/omp_hello.zip).


## Príklady

Pozrite si materiály z prednášky a príklady v **PaPP/examples/openmp**. Precvičte si základné konštrukcie na vytváranie paralelnej oblasti (`#pragma omp parallel`) a základné konštrukcie na deľbu práce (`#pragma omp for`, `#pragma omp sections`, `#pragma omp single`). Pre direktívu `#pragma omp for` si pozrite a vyskúšajte rôzne spôsoby plánovania iterácií cyklu na vykonanie (klauzula `schedule()`). Pozrite si konštrukcie na definovanie rozsahu platnosti údajov ( `private`,`shared` ,`firstprivate` ,`lastprivate` ,... ).

## Úloha
Pozrite si implementáciu výpočtu n-tého prvku Fibonacciho postupnosti za použitia OpenMP ([fib_omp.c](labs/fib_omp.c)). Použite OpenMP pre paralelizáciu rekurzívnej verzie algoritmu quicksort ([qs.c](labs/qs.c)).
