import sys
import math
from collections import Counter

k, n = [int(s) for s in sys.stdin.readline().strip().split()]
a = [int(s) for s in sys.stdin.readline().strip().split()]

longest = -1
prev = a[0]

for i in range(1, n):
    ai = a[i]
    dist = ai - prev
    longest = max(longest, dist)
    prev = ai

last_cand = k - a[-1] + a[0]
longest = max(longest, last_cand)

print(k - longest)
