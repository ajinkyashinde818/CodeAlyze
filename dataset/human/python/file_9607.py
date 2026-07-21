import sys
n,k = list(map(int,input().split()))
a = list(map(int,input().split()))

kyori = [-1]*n

now = 0;kyori[now] = 0
jyunkan = 0;v = 0
for i in range(n):
    tugi = a[now] - 1
    if kyori[tugi] != -1:
        jyunkan = kyori[now] + 1
        v = tugi
        break
    kyori[tugi] = kyori[now] + 1
    if kyori[tugi] == k:
        print(tugi + 1)
        sys.exit()
    now = tugi
k -= kyori[v]
mawaru = jyunkan - kyori[v]
amari = k % mawaru

now = v;cunt = 0
for i in range(amari):
    now = a[now] - 1
    
print(now + 1)
