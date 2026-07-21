s = input()  # "3 2"
n, m = s.split()  # ("3", "2")
n = int(n)  # 3
m = int(m)  # 2

a = []
for i in range(0, n):
    a.append(input())

b = []
for i in range(0, m):
    b.append(input())

def same(a, b, i, j):
    for k in range(0, len(b)):
        if a[i + k][j:j + len(b)] != b[k]:
            return False
    return True

is_same = False
for i in range(0, n - m + 1):
    for j in range(0, n - m + 1):
        if same(a, b, i, j):
            is_same = True
            break
    else:
        continue
    break

print("Yes" if is_same else "No")
