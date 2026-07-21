n, m = map(int, input().split())
b1 = [False for i in range(n)]
bn = [False for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    if a > b:
        a, b = b, a
    if a == 0:
        b1[b] = True
    if b == n - 1:
        bn[a] = True
for i in range(n):
    if b1[i] and bn[i]:
        print("POSSIBLE")
        import sys
        sys.exit()
print("IMPOSSIBLE")
