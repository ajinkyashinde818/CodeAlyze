import sys
input = sys.stdin.readline

import numpy as np

R,G,B,N = map(int,input().split())

count = 0
R_limit = N // R

for i in range(R_limit,-1,-1):
    N_temp = N - i*R
    G_limit = N_temp // G
    for j in range(G_limit,-1,-1):
        N_temp2 = N_temp - j * G
        B_mod = N_temp2 % B
        if B_mod == 0:
            count = count+1

print(count)
