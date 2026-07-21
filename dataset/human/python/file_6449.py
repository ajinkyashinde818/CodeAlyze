import sys
input = sys.stdin.readline
I=lambda:int(input())
MI=lambda:map(int,input().split())
LI=lambda:list(map(int,input().split()))

N=I()

if N%2:
    print(0)
else:
    res=0
    i=1
    while 1:
        dr=N//(2*5**i)
        if dr:
            res+=dr
        else:
            break
        i+=1
    print(res)
