import sys
input=sys.stdin.readline
n=int(input())
A=list(map(int,input().split()))
B=[]
for a in A:
    B.append(abs(a))
cnt=0
for a in A:
    if a==0:
        cnt=0
    if a<0:
        cnt+=1
print(sum(B)-min(B)*2 if cnt%2 else sum(B))
