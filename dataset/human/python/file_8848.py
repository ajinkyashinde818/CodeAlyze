import sys

k,n = (int(i) for i in input().split())

a = [int(i) for i in input().split()]



kyori = [None]*(n-1)

kyori[0] = a[0]-a[-1]+k
for i in range(1,n-1):
    kyori[i] = a[i+1]-a[i]

max = max(kyori)

print(k-max)
