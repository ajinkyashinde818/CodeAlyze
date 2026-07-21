import heapq
n = int(input())
a = list(map(int,input().split()))
count = 0
for i in a:
    if i < 0:
        count += 1
abs_a = list(map(abs,a))
if 0 in a or count % 2 == 0:
    print(sum(abs_a))
else:
    heapq.heapify(abs_a)
    min_a = heapq.heappop(abs_a)
    print(sum(abs_a)-min_a)
