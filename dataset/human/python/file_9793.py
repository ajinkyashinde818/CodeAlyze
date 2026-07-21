import sys
sys.setrecursionlimit(10 ** 5 + 10)
def input(): return sys.stdin.readline().strip()

def resolve():
    n,k=map(int,input().split())
    A=list(map(int,input().split()))
    visited=[1]+[0]*(n-1)
    vil=[0]*(n*10)

    nowi=1
    cnt=1
    while True:
        nxti=A[nowi-1]-1 #0ind
        cnt+=1
        if visited[nxti]==0:
            visited[nxti]=cnt
            vil[cnt-1]=nxti
            nowi=nxti+1 # 1ind
        else:
            prime=visited[nxti]
            loop=cnt-visited[nxti]
            break
    
    if k<=prime:
        print(vil[k]+1)
    else:
        mod=((k+1)-(prime-1))%loop
        if mod==0:
            mod=loop
        print(vil[prime-2+mod]+1)
    

    

    
resolve()
