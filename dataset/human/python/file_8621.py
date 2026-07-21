"""Boot-camp-for-Beginners_Easy012_C_Next-Prime_30-August-2020.py"""
import numpy as np

K, N = map(int, input().split())
A = list(map(int, input().split()))

theta = []
for i in range(len(A)):
    if i == len(A)-1:
        theta.append((K-A[i]+A[0]))
    else:
        theta.append((A[i+1]-A[i]))
#print("sum",sum(theta))
theta.remove(max(theta))
#print(theta)
s=0
for j in range(len(theta)):
    s+=theta[j]
#print(s)
l_min=s
print(l_min)
