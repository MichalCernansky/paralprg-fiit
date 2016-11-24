---
layout: page
title: Cvičenie 9 (10)
category: lab
---

## MPI v CodeBlocks

0. Spustiť CodeBlocks pomocou „codeblocks.bat“ na jednom PC a pripraviť .exe súbor
0. Program musí byt kompilovaný s argumentom „-lmpi“
  - Project -> Build Options -> Linker Settings -> pole Other Link Options -> pridať „-lmpi“
0. Spustiť program smpd a nechať ako bežiaci proces Pomocou CMD alebo PowerShell:
```
# cd %CodeBlocksPath%/toolchains/bin
# ./smpd -d
```
0. Skompilovaný (.exe) súbor musí byť umiestnený v rovnakom adresári na oboch PC
0. V CodeBlocks nastaviť argumenty programu
  - Project -> „Set programs arguments...“
  - Vybrať požadovaný „build target“
  - Do poľa „Program arguments“ pridať požadované argumenty, napríklad:
  - -mpi mpiexec -hosts 4 192.168.0.1 192.168.0.2 192.168.0.2 192.168.0.2
  - argument -hosts špecifikuje počet inštancií programu, ktorých miesto behu je identifikované pomocou následne uvedených IP adries.
  - Prvá uvedená adresa (192.168.0.1) špecifikuje, kde bude spustený proces s ID = 0, teda vo väčšine prípadov master, ktorý riadi rozdeľovanie spracovania, respektíve zobrazuje výsledok spracovania
  - V uvedenom príklade hovoria zvyšné 3 adresy o tom, že okrem master procesu majú byť spustené ďalšie 3 procesy na stroji s adresou 192.168.0.2
0. Na jednom PC spustiť program priamo z CodeBlocks pomocou „Build and Run“
0. Ak je .exe súbor správne umiestnený na ostatných PC, na každom PC sa spustí požadovaný počet inštancií programu

### Poznámky:
- Počítače musia byť na jednej sieti a dokázať spolu komunikovať
- overiť pomocou PING
- Pozor na firewall – najlepšie vypnúť, alebo pridať výnimky
- PC možno prepojiť aj priamo ethernetovým káblom, pravdepodobne nutné manuálne nastaviť IP adresy, napríklad 192.168.0.1 a 192.168.0.2
  - Ethernet Properties -> IPv4 -> Settings
  - Zadať IP
  - Zadať masku (napr 255.255.255.0)
  - Zadať Gateway -> ako IP
  - Zadať DNS -> ako IP



## MPI pre Mac OS X

0. Potrebné nainštalovať homebrew (http://brew.sh):
```
$ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

0. Potom nainštalovať balíček pre podporu mpi: brew install open-mpi:
```
$ brew install open-mpi
```
0. Kompilovať program pomocou mpicc, napríklad:
```
$ mpicc mpi_hello.c -o mpi_hello  
```
Ak si chcete pozrieť, s akými parametrami (knižnice, adresáre pre knižnice, hlavičkové súbory, ...), použite prepínač show, ten vám ukáže, aký kompilátro sa použije:
```
$ mpicc mpi_hello.c -o mpi_hello -show
```
0. Spustite program pomocou mpirun:
```
$ mpirun -n 4 --hosts 127.0.0.1,127.0.0.1,127.0.0.1,127.0.0.1 mpi_hello
```
Namiesto uvedenia uzlov je možné použiť prepínač --hostfile:
```
$ cat my-hostfile
192.168.0.1 slots=4
192.168.0.2 slots=4
$
$ mpirun -n 4 --hostfile my-hostfile mpi_hello
```

### Poznámky:
- Ak spúštate program na viacerých počítačoch, nie je potrebné spúšťať žiadny daemon (smpd), open-mpi runtime sa stará o všetko.
