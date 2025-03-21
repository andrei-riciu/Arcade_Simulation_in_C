# Arcade_Simulation_in_C

Acest proiect consta in implementarea in limbajul C a unei simulari de joc tip ARCADE cu ajutorul matricilor si a pointerilor.
Cerintele pentru fiecare task pot fi gasite aici https://ocw.cs.pub.ro/courses/programare/teme_2024/tema1_2024_cbd

## main

In functia "main" se initializeaza si se citesc variabilele de lucru de la stdin, atat numarul task-ului cat si elementele matricei, iar apoi cu ajutorul unui "switch" se rezolva taskul cerut.

## Task1

Pentru a rezolva Task1 am realizat functia "perm" care realizeaza permutarea circulara a unei coloane "col" de "nr_poz" ori, modificand in memorie matricea "mat". In "main" este apelata functia respectiva si sunt afisate elementele matricei.

## Task2

Pentru rezolvarea Task2 am realizat functia "calcul_lin" care calculeaza scorul obtinut prin combinatii castigatoare pe linii si functia "calcul_diag" care calculeaza scorul obtinut prin combinatii castigatoare pe diagonale. Functiile sunt apelate in "main", iar apoi sunt applicate bonusurile de scor.

## Task3

Pentru rezolvarea Task3 m-am ajutat de functia realizata anterior "perm" si am mai implementat functia "total_score" care cu ajutorul celor anterioare calculeaza scorul total intr-o configuratie a matricei. Astfel am insumat scorurile tuturor celor "T" configuratii.

## Task4 

Pentru rezolvarea Task4 am parcurs elementele cadranului, iar pentru fiecare, daca acesta era semnificativ, adica daca putea aduce schimbari la scorul din configuratia respectiva, l-am inlocuit cu valoarea unuia dintre vecinii lui, am calculat scorul si l-am comparat cu scorul maxim posibil obtinut.

## Task5

Pentru rezolvarea Task5 am parcurs coloanele matricei, iar pentru fiecare pereche de cate 2 coloane am realizat fiecare configuratie a matricei si am calculat scorul si l-am comparat cu cel maxim posibil obtinut.

