import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 9)
MOD = 10 ** 9 + 7

N, K = map(int, input().split())
A = [0] + list(map(int, input().split()))

check = [True] * (N + 1)
count = 0

now = 1
while check[A[now]] and K:
    now = A[now]
    check[now] = False
    K -= 1

if K == 0:
    print (now)
    exit()


check = [True] * (N + 1)
count = 0

while check[A[now]] and K:
    now = A[now]
    check[now] = False
    count += 1
    K -= 1

if K == 0:
    print (now)
    exit()

K %= count

while K:
    K -= 1
    now = A[now]

print (now)
