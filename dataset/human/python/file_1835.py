n, m = map(int, input().split())
a = []
b = []
flag = False
def check(offset=[0, 0]):
    for i in range(m):
        for j in range(m):
            if a[i + offset[0]][j + offset[1]] != b[i][j]:
                return 1
    return 0

for i in range(n):
    a.append(list(input()))
for i in range(m):
    b.append(list(input()))

for i in range(n - m + 1):
    for j in range(n - m + 1):
        if check((i,j)) == 0:
            flag = True

if flag:
    print("Yes")
else:
    print("No")
