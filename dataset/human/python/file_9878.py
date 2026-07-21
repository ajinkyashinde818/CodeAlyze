from collections import deque
import numpy as np
n,k =map(int,input().split())
A = [int(x)-1  for x in input().split()]
arrive_time = [0]*n
time = 1
done = [0]*n
done[A[0]] = 1
arrive_time[A[0]] = time
last = 0
next = A[0]
while True:
    v = next
    if done[A[v]] == 0:
        done[A[v]] = 1 
        time += 1
        arrive_time[A[v]] = time
        next = A[v]
    else:
        last = A[v]
        break  

if time >= k:
    for i,a in enumerate(arrive_time):
        if a == k:
            print(i+1)
else:
    roop = time - arrive_time[last] + 1
    nokori = (k-arrive_time[last])%roop
    ans = nokori+arrive_time[last]
    for i,a in enumerate(arrive_time):
        if a == ans:
            print(i+1)
