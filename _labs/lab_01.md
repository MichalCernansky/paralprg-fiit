---
layout: page
title: Cvičenie 1
category: lab
---


GIT repozitár http://github.com/drahosp/PaPP obsahuje kompletné vývojové prostredie spolu s príkladmi pre Posix Threads, MPI a OpenMP.

```
> mkdir PaPP
> cd PaPP
> git clone https://github.com/drahosp/PaPP.git
```

alebo "Clone or download" zo stranky projektu.

### Win

Spúštajte prostriedie pomocou **codeblocks.bat**

```
> cd PaPP
> codeblocks.bat
```
Vyskúšajte si príklady v **PaPP/examples/examples.workspace**. Naučte sa používať prostredie, hlavne "targets", projekty v **examples.workspace** ich používajú. "targets" je potrebné prepínať a v prípade nového do projektu pridávaného zdrojového súboru je vhodné vytvoriť nový "target".


### Mac OS a Linux

Vyskúšajte si príklady v **PaPP/examples/pthreads**. Napr.:

```
> cd PaPP/examples/pthreads
> gcc -lpthread pt_basic.c -o pt_basic
> ./pt_basic
```

Alebo si nainštalujte Vami preferované vývojové prostredie pre C, napr. XCode alebo CLion. Vždy je potrebné linkovať pthread programy s knižnicou **libpthread**.
