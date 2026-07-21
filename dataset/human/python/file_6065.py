import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

s = 0
p_a = -1
for now_a in a:
    s += b[now_a-1]
    if now_a - p_a == 1:
        s += c[p_a-1]

    p_a = now_a

print(s)
