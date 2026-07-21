from sys import stdin
N = int(stdin.readline().rstrip())
A = [int(x) for x in stdin.readline().rstrip().split()]
cnt = 0
abs_sum = 0
for i in A:
    abs_sum += abs(i)
    if i < 0:
        cnt += 1
mi = min([abs(i) for i in A])
if cnt % 2 == 0:
    print(abs_sum)
else:
    print(abs_sum-(mi*2))
