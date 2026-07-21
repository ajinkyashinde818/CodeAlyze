import numpy as np
INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
def do():
    n,k=INTM()
    a=LIST()
    vst=[0]*n
    vst[0]=1
    loop=[]
    temp=1
    for i in range(k):
        temp=a[temp-1]
        if vst[temp-1]==0:
            vst[temp-1]=1
        elif vst[temp-1]==1:
            loop.append(temp)
            vst[temp-1]=2
        else:
            temp=loop[-1]
            cost=k-i
            break
        if i==k-1:
            cost=0
    if cost!=0:
        print(loop[(cost-1)%len(loop)])
    else:
        print(temp)
                    
                
if __name__ == '__main__':
    do()
