from sys import stdin, stdout
input = stdin.readline
print = stdout.write
n = int(input())
arr = [int(i) for i in input().split()]
sm = sum(abs(i) for i in arr)
mn = min(abs(i) for i in arr)
nc = sum(i < 0 for i in arr)
if nc % 2 == 0: print(str(sm))
else: print(str(sm - 2 * mn))
