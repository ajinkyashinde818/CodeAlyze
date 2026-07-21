import sys

n=int(input())

if n==1:
    print("Yes")
    print(2)
    print("1 1")
    print("1 1")
    exit()

def sss(n):
    if n==2:
        return [[1,2],[1,3],[2,3]]
    N=n*(n+1)//2
    ss=[[i for i in range(N-n+1,N+1)]]
    j=N-n+1
    for i in sss(n-1):
        i.append(j)
        ss.append(i)
        j+=1

    return ss
    

ok=0
for i in range(1000):
    if n == (i+2)*(i+3)//2:
        ok=1
        k = i+3
        gen = k-1
        break

# n= k+1 C 2


if ok==0:
    print("No")

else:
    print("Yes")
    print(k)
    
    for i in sss(gen):
        print(*([len(i)]+i))
