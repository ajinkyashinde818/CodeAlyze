import heapq
import sys
input = lambda: sys.stdin.readline().rstrip()
n = int(input())
a = list(map(int,input().split()))
cal = []
heapq.heapify(cal)
minus = 0
zero = False
for i in a:
    if i == 0:
        zero = True
    if i < 0:
        minus += 1
    heapq.heappush(cal,abs(i))

if minus % 2 == 0 or zero:
    print(sum(cal))
else:
    adjust = heapq.heappop(cal)
    print(sum(cal)-adjust)
