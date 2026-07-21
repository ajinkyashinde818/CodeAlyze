import sys
input = sys.stdin.readline

n = int(input())

def factorization(n):
    arr = []
    wari = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if wari%i==0:
            cnt=0
            while wari%i==0:
                cnt+=1
                wari //= i
            arr.append([i, cnt])

    if wari!= 1:
        arr.append([wari, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

m = 0

if n == 1:
    print(0)
else:
    for i in factorization(n):
        sankaku = (int((1+8*i[1])**0.5)-1) // 2
        m += sankaku   
    print(m)
