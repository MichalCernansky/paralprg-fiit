---
layout: page
title: Cvičenie 3
category: lab
---


## Synchronizáca pomocou podmienených premenných / monitorov.

Pozrite si materiály z prednášky a príklady v **PaPP/examples/pthreads**: **pt_condition**. Pozrite si dokumentáciu na na používanie podmienených premenných resp. monitorov vo Vami zvolenom jazyku.


0. Vytvorte program, v ktorom najskôr vytvoríte prvé a potom druhé vlákno. Následne zabezpečte, aby prvé vlákno vypísalo “zelena” až keď druhé vlákno vypíše “červena”.
   0. Program riešte pomocou podmienených premenných a mutexov.
   0. Program riešte pomocou semafórov.

0. Rozšírte zadanie tak, aby vlákna cyklicky vypisovali “cervena” “zelena”, postupne 10x (10 cyklov a potom program skončí).

0. Rozšírte zadanie na tri vlákna, ktoré budú vypisovať “cervena” “oranzova” “zelena”.

0. Rozšírte zadanie na N vlákien, ktoré budú vypisovať “1” “2” “3” ... “N”.

0. Napíšte program, v ktorom v ktorom najskôr vytvoríte dve vlákna. Následne globálnu premennú "counter" jedno vlákno každú sekundu inkrementuje postupne na hodnoty 1 až 10 a následne druhé vlakno na hodnoty 11 až 20 a potom zase prvé vlákno na 21 až 30.
   0. Program riešte pomocou podmienených premenných a mutexov.
   0. Program riešte pomocou semafórov.

0. Napíšte program, v ktorom v ktorom najskôr vytvoríte vlákna 1 až N. Následne vlákna postupne od prvého po N-té každú sekundu inkrementujú globálnu premennú "counter". Keď N-té vlákno inkrementuje “counter” program končí.
   0. Program riešte pomocou podmienených premenných a mutexov.
   0. Program riešte pomocou semafórov.

10. Rozšírte zadanie tak, že po N-tom vlákne bude nasledovať 1. vlákno. Program skončí, keď premenná counter nadobudne hodnotu 3*N (vykonajú sa 3 cykly).
