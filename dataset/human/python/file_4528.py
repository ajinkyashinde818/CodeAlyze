import numpy as np

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

kaisa = [1]
for i in range(100):
    kaisa.append(kaisa[-1]+(i+1))


N = int(input())
soinsu = np.array(factorization(N))
tate = soinsu.shape[0]
kaisawa = []
wa = 0
for i in range(100):
    kaisawa.append(((i+2)*(i+1)//2))

for i in range(tate):
    for j in range(100):
        if soinsu[i, 1] < kaisawa[j]:
            wa += j
            break

if N == 1:
    wa = 0

print(wa)
