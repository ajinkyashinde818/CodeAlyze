from sys import stdin

N = int(stdin.readline().rstrip())
A = [int(x) for x in stdin.readline().rstrip().split()]
A_abs = [abs(x) for x in A]

minus_cnt = len([x for x in A if x < 0])

res = 0

if minus_cnt % 2 == 0:
    res = sum(A_abs)
else:
    res = sum(A_abs) - 2*min(A_abs)

print(res)
