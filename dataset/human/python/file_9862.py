from sys import stdin
N,K=list(map(int,(stdin.readline().strip().split())))
A=list(map(int,(stdin.readline().strip().split())))
cycle=[1]
count=[0]*N
tele=0
count[tele] += 1
while(True):
    cycle.append(A[tele])
    tele=A[tele]-1
    count[tele] += 1
    if count[tele] == 2:
        break
a=cycle.index(tele+1)
if K<len(cycle):
    print(cycle[K])
else:
    num=len(cycle[a:-1])
    num=(K-len(cycle[:a]))%num
    print(cycle[num+len(cycle[:a])])
