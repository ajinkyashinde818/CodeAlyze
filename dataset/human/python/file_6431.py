def wczytaj_liste(): 
    wczytana_lista = input()
    lista_znakow = wczytana_lista.split()
    ostateczna_lista = []
    for element in lista_znakow:
        ostateczna_lista.append(int(element))
    return ostateczna_lista

def Double_Factorial():
    N = wczytaj_liste()[0]
    if N < 10: 
        print (0)
    elif N%2 == 1: 
        print(0)
    else:
        podzielnik = 10
        wynik = 0
        while podzielnik <= N:
            wynik += N//podzielnik
            podzielnik *= 5
        print(wynik)
            
Double_Factorial()
