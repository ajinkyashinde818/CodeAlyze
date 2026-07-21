import math
import sys
input = sys.stdin.readline


K,S = map(int, input().split())
n = 0
up = math.floor(K)
for i in range(0,K+1):
    for j in range(0, K+1):
        if(0<= S-i-j <=K):
            n +=1
        else:
                n =n

print(n)
