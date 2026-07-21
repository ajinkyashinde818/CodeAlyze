import sys
input = lambda : sys.stdin.readline().strip()
n,k = map(int,input().split())
a = list(map(int,input().split()))
sala = set([0,a[0]-1])
f = 0
s = a[0]-1
power = 1
length = 1
while f!=s:
    if length==power:
        power*=2
        length=0
        f = s 
    s = a[s]-1
    sala.add(s)
    length+=1
start = len(sala)-length
if k<=start:
    cur = 0 
    while k:
        k-=1
        cur = a[cur]-1
    print(cur+1)
else:
    k-=start 
    k%=length
    f = 0
    s = 0 
    while length:
        s = a[s]-1
        length-=1
    while s!=f:
        s = a[s]-1
        f = a[f]-1
    cur = f 
    while k:
        cur = a[cur]-1
        k-=1
    print(cur+1)
