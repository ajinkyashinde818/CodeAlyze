n, m = map(int, input().split())

area_a = []
for i in range(n):
    array = input()
    area_a.append(array)

area_b = []
for i in range(m):
    array = input()
    area_b.append(array)

def check(i, j):
    flag = True
    for u in range(m):
        x = area_a[i+u][j:j+m]
        if x != area_b[u][:]:
            flag = False
            break
        else:
            continue
    if flag is True:
        print('Yes')
        exit()

for i in range(n-m+1):
    for j in range(n-m+1):
        check(i,j)

print('No')
