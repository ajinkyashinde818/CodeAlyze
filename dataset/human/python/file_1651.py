a = input().split()
n = int(a[0])
m = int(a[1])
img1 = []
for i in range(n):
    img1.append(input())
img2 = []
for j in range(m):
    img2.append(input())

def match(x, y):
    for k in range(m):
        for l in range(m):
            if img1[x+k][y+l] != img2[k][l]:
                return False
    return True

found = False
for i in range(n-m+1):
    for j in range(n-m+1):
        if match(i, j):
            found = True
if found:
    print("Yes")
else:
    print("No")
