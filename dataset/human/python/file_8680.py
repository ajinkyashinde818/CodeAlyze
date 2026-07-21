import sys
 
k, n = map(int, sys.stdin.readline().split())
a = [int(i) for i in sys.stdin.readline().split()]
a.sort()
max_dist = 0
for i in range(1, n):
	max_dist = max(a[i] - a[i - 1], max_dist)
    
if len(a) != 0:
	max_dist = max(a[0] + k - a[-1], max_dist)
sys.stdout.write(str(k - max_dist))
