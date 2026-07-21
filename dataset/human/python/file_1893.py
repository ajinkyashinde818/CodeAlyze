import sys
n, m = map(int, input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]
index = n - m + 1


def check(a, b):
    for u, v in zip(a, b):
        for i in range(m):
            if u[i] == v[i]:
                pass
            else:
                return False
    return True


for i in range(index):
    x = a[i:i + m]
    for j in range(index):
        r = []
        for w in x:
            y = w[j:j+m]
            r.append(y)
        if check(r, b):
            print("Yes")
            sys.exit()

print("No")
