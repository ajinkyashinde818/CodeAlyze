from collections import deque
n,k = map(int, input().split())
a = [0]+list(map(int, input().split()))

genzaiti=1
otozure=[-1]*(10**6)
hantei=True

otozure[1]=0
houmon=0
idou_kaisuu=0

while k>0:
    idou_kaisuu+=1
    k-=1
    genzaiti=a[genzaiti]

    if hantei:
        if otozure[genzaiti]!=-1:
            kaiten=idou_kaisuu-otozure[genzaiti]
            k%=kaiten
            hantei=False
    
    otozure[genzaiti]=idou_kaisuu

print(genzaiti)
