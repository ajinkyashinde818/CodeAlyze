import sys
readline = sys.stdin.buffer.readline
def even(n): return 1 if n%2==0 else 0

k,n = map(int,readline().split())
lst1 = list(map(int,readline().split()))

dist = 0

for i in range(n-1):
    dist = max(dist,abs(lst1[i]-lst1[i+1]))

dist = max(dist,k-lst1[-1]+lst1[0])

print(k-dist)
