import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))
n=I()
As=LI()
Bs=LI()
Cs=LI()
satis=Bs[As[0]-1]
for i in range(1,n):
    satis+=Bs[As[i]-1]
    if As[i]==As[i-1]+1:
        satis+=Cs[As[i-1]-1]
print(satis)
