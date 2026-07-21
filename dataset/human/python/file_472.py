import bisect
n = int(input())
A = [int(a) for a in input().split()]
A.sort()
A_abs = [abs(ab) for ab in A]
A_abs.sort()
sum_abs = sum(A_abs)

wh = bisect.bisect_left(A, 0)
dev2 = wh % 2
if dev2 == 0:
  print(sum_abs)
else:
  print(sum_abs - 2 * A_abs[0])
