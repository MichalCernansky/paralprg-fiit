---
layout: page
title: Úlohy a projekt
---

V priebehu semestra je potrebné vypracovať a odprezentovať úlohu riešenú sa na určenom cvičení a dva projekty.

Pthreads - 5 týžden na cvičeniach, bude zadaná a vypracovaná na cvičení, max. čas na vypracovanie 90 min, 10b  
OpenMP+MPI projekt - 10 týždeň, 20b  
Zadanie projektu – 10 týždeň  
Projekt – 12 týždeň, 20b  

Prvá úloha bude zadaná až na cvičení a bude ju potrebné vypracovať v priebehu cvičenia.

Projekty budú zadané a dohodnuté v predstihu, bude možné ich vypracovať mimo cvičení a na cvičeniach ich prísť odprezentovať. Za každý týždeň oneskoreného odprezentovania bude projekt penalizovaný 2 bodmi. Bližšie informácie o môžných témach sú nižšie. Prezentuje sa produkt a odovzdáva sa krátka správa spolu s produktom.


## Úloha (Synchronizácia)

Príklady, ktoré je vhodné si preriešiť (z cvičení a prednášok):

- Jednoduché konštrukcie
- Vytváranie vlákien
- Čakanie na ukončenie vlákna
- Práca s mutexami
- Práca s podmienenými premennými
- Práca so semáfórmi
- Jednoduché synchronizačné konštrukcie
- Vzájomné vylučovanie
- Signalizácia
- Barieróvá synchronizácia
- Znovupoužiteľná bariéra
- Synchronizačné problémy
- Producenti a konzumenti
- Čitatelia a pisatelia
- Obedujúci filozofi


## Projekt č. 1 (OpenMP a MPI)

Zvoľte si výpočtovo náročnú úlohu a preverte možnosti aplikovania paralelného spracovania na jej riešenie. Využite paralelné programátorské modely OpenMP, MPI a dosiahnuté zrýchlenia porovnajte a komentujte. Diskutujte témy s cvičiacimi.

Možné témy:

- Počítačová grafika
+ Generovanie fraktálových obrazcov
+ Filter
- Strojové učenie
- Dopredné šírenie v neurónových sieťach
- Zhluková analýza rozsiahlých dát pomocou algoritmu k-means
- Prípadne aj vlastná téma po dohode s cvičiacim

Podmienky vypracovania:

- Riešenie využíva oba paralelné programátorské modely, aj OpenMP aj MPI v jednom riešení.
- Spravte experimenty pre rôzne konfigurácie paralelného systému, vhodne zvoľte kombinácie z uvedeného (2 uzly sú podmienkou):
  - 1 a 2 (prípadne aj viacej) uzlov = zosieťovaných počítačov,
  - 1,2,4 a 8 MPI procesov,
  - 1,2,4 a 8 OpenMP vlákien.
- Prezentuje a odovzdáva sa aj stručná dokumentácia obsahujúca krátky popis reišenia a hlavne dosiahnuté výsledky experimentov s rôznymi komfiguráciami paralelného systému.
- Riešenie musí byť schopné pracovať na viacerých uzloch (N > 2), pri prezentácii preukážte schopnosť riešenia bežať na 2 rôznych uzloch.
- Pri prezentácii zdôvodnite použitie zvolených konštrukcií hlavne pre OpenMP ale aj MPI, musíte poznať aj Vami nepoužité konštrukcie (v rozsahu, ako sme sa im venovali na prednáškach). Pre MPI použite kolektívne komunikačné operácie.




### Generátor Fraktálov

Implementujte generator fraktalu[1] ktory je schopny realizovat jeho vypocet paralelne za pomoci OpenMP a MPI. V implementacii mozete pouzit vizualizacnu kostru v distribuovanom prostredi pouzivanom na cviceniach a doplnte jej funkciu GenerateImage, alebo iný zdroj. Cielom ulohy je generovat fraktal za co najmensi cas pricom mnozstvo iteracii pri generovani bodu vo fraktale je variabilne. Do kostry implementujte i funkcionaltu merajucu rychlost vypoctu. Za plus sa povazuju interaktivne riesenia umoznujuce zoom a posun vo farebnom fraktale.

###  Filter Obrazu

Implementujte filter obrazu vyuzivajuci konvolucnu maticu[2] za pomoci OpenMP a MPI alebo ich kombinacie. Na implementaciu mozete pouzit existujuci iny zdroj. Ako zdrojovy obraz mozete pouzit sum nahodne generovanych hodnot a tiez nacitany obrazu zo suboru; pre dalsie iteracie filtra pouzite ako vstup jeho predosli vystup. Implementujte funkcionaltu merajucu rychlost vypoctu.

### Zhluková analýza rozsiahlých dát pomocou algoritmu k-means

Implementujte algoritmus k-means [3] a využite paralelné programátorské modely OpenMP a MPI. Implementácia musí byť schopná načítať textový súbor s reálnymi číslami, kde každý riadok zodpovedá jednému pozorovaniu (jednému vektoru v množine). Súbor si vhodne vygenerujte tak aby zodpovedal zvolenému počtu zhlukov (zhluk vybraný z rovnomerného rozdelenia a bod v rámci zhluku podľa Gaussovho = normálneho rozdelenie). Pre klastrovací program je počet pozorovaní, rozmer vektora pozorovania a tiež počet zhlukov možné zadať v príkazovom riadku resp. si to program určí zo vstupného súboru. Inicializujte centrá zhlukov nahodým výberom prvkov z množiny a zastavte trénovanie, keď už nedochádza k zmenám centier zhlukov. Počas trénovania počítajte mieru WCSS (Within cluster sum of squares) a tiež meranie času výpočtu.

### Dopredné šírenie v neurónových sieťach

Implementujte algoritmus dopredného šírenia v doprednej viacvrstvovej perceptrónovej sieti [4] a využite paralelné programátorské modely OpenMP a MPI. Implementácia musí byť schopná načítať textový súbor s reálnymi číslami, kde každý riadok zodpovedá jednému vstupnému vektoru. Počet krokov dopredného šírenia, počet vstupných, skrytých a výstupných neurónov nech je možné zadať v príkazovom riadku resp. si to program určí zo vstupného súboru. Na konci simulácie nech aplikácia zapíše výstupy siete do textového súboru. Realizujte meranie času výpočtu.

[1] http://en.wikipedia.org/wiki/Mandelbrot_set  
[2] http://www.gamedev.net/reference/programming/features/imageproc/page2.asp  
[3] http://en.wikipedia.org/wiki/K-means_clustering  
[4] http://www2.fiit.stuba.sk/~cernans/nn/nn_download/UNS.zip  


## Projekt č. 2 (Téma podľa záujmu študenta)

Príklady tém:

- Použitie metód a prostriedkov paralelného spracovania vo vašej bakalarskej práce alebo semestrálnom projekte – oznámiť aj vedúcemu práce
- Spracovanie a odprezentovanie zvolenej problematiky nepokrytej v prednáškach
- Spracovanie synchronizačného problému tak, ako sú spracovaní obedujúci filozofi
- Spracovanie jednoduchej synchronizačnej úlohy (ako 1. úloha pri počítačoch) + vzorové riešenie úlohy
- Témy z oblasti strojového učenia
- Témy z oblasti počítačovej grafiky
