from bisect import bisect_left
n = int(input())
a = list(map(int, input().split()))
a.sort()
b = [abs(i) for i in a]
b.sort()

i = bisect_left(a, 0)
if i % 2==0:
    print(sum(b))
else:
    print(sum(b) - 2*b[0])
