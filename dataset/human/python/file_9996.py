def wczytaj_liste(): 
    wczytana_lista = input()
    lista_znakow = wczytana_lista.split()
    ostateczna_lista = []
    for element in lista_znakow:
        ostateczna_lista.append(int(element))
    return ostateczna_lista

def NWD(A,B): 
    if B > A: 
        A, B = B, A 
    if B == 0: 
        return A
    else: 
        return NWD(A%B,B)

def party(): 
    A, B = wczytaj_liste()
    najwiekszy_dzielnik = NWD(A,B)
    odp = A*B//najwiekszy_dzielnik
    print(odp)

party()
