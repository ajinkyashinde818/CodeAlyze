N = int(input())
S = input()
list_s = list(S)

from collections import Counter

counter = Counter(list_s)

LARGE_NUM = 10**9 + 7

result = 1
for _, cnt in counter.items():
    result *= cnt+1
    result %= LARGE_NUM
print(result-1)
