---
layout: page
title: Cvičenie 6
category: lab
---


Riešte na cvičení zadanú úlohu, na riešenie máte 90 minút, výsledný súbor odovzdajte do AIS (iba jediný súbor so zdrojovým kódom). Ak riešite v C (posic threads), použite kostru programu. Ak riešite vo Vami zvolenom jazyku, kostru si musíte vytvoriť.

- Riešte s použitím podmienených premenných resp. monitorov, nie pomocou semafórov.
- Na riešenie máte 90 minút.
- Výsledný súbor odovzdajte do AIS po dokončení vypracovania - iba jediný súbor so zdrojovým kódom!.
- Odovzdajte aj nefunkčné alebo neúplne zadanie.
- sociálne siete, alebo akákoľvek iná komunikácia je prísne zakázaná
- Pokúste sa programovať čo najprehľadnejšie :-)
- ak chcete, prineste si vlastné PC, úlohu môžete robiť na nich
- môžete používať akékoľvek materiály, ktoré máte k dispozícií
- povolený jazyk je C (alebo vami vybraný jazyk C++, Java, C#, ... (nič uletené))
- hodnotí sa hlavne myšlienka, a správne použitie synchronizačných primitív a zložitejších konštrukcií (bariéra, turniket, iné konštrukcie, ...)
- každý príďte na cvičenie, ktoré máte oficiálne zapísané, ak chcete inak (odôvodnene), napíšte mi mail
- je možný opravný termín v dosiaľ neurčenom čase a mieste, daného termínu sa môžu zúčastniť všetci, teda aj tí, čo získali minimálne body

Niekoľko tipov a poznámok k úlohám:
- pozrite si poriadne prednášku s názvom "synchronizácia" a správne použitie synchronizačných konštrukcií
- dôležité sú bariéra, turniket, zapisovatelia a čitatelia, producenti a konzumenti, atď.
- je dôležité aby ste vedeli, kedy ktorú konštrukciu použiť a nesnažili sa vymýšľať zbytočne vlastné riešenia, niekedy je ale potrebné vlastné riešenia vymyslieť (napríklad "organizmy" v [uloha1priklady.zip](labs/uloha1priklady.zip))
- dávajte si pozor na obsadzujúce čakanie - to je veľmi nežiadúce
- binárny semafór nie je mutex, semafory sú zakázané, mutexy nie
- vo väčšine prípadov je lepšie zavolať broadcast, ako signal. Ak sa pri signale zobudí nesprávne vlákno, ktorého podmienka nie je splnená, opätovne sa uspí a nastane deadlock, dávajte si na to pozor

Správne ošetrenie ukončenia:
V prvom rade je potrebné zabezpečiť, aby sa po uplynutí limitu už nezačala ďalšia činnosť. Za "činnosť" možno považovať napríklad také "pečenie", alebo "prípravu", alebo "maľovanie", no nie lockovanie, alebo unlockovanie mutexu. Ak teda ešte nezačala niektorá z týchto činností, už sa ani nezačne, no ak beží, nechajte ju kľudne dobehnúť. Ďalej je potrebné myslieť na to, že ak uplynie časový limit, treba pred skončením programu slušne počkať, kým všetky vlákna dobehnú (join). Treba si uvedomiť, že niektoré môžu ostať čakať na nejakom waite, pričom ich už nikto nemusí zobudiť, keďže ostatné vlákna už dobehli. Preto je možno dobré na konci pre príslušné podmienené premenné zavolať napríklad broadcast aby sa uvoľnili a hneď skončili.
