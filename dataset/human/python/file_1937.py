import sys
input = sys.stdin.buffer.readline

n, m = [int(i) for i in input().split()]

img_a = []
img_b = []

for i in range(n):
    img_a.append(list(input().strip()))

for i in range(m):
    img_b.append(list(input().strip()))


if img_a == img_b:
    print("Yes")
    sys.exit()

for i in range(0, n - m + 1):
    for j in range(0, n - m + 1):
        grid = [line[j:j + m] for line in img_a[i:i + m]]
        if grid == img_b:
            print("Yes")
            sys.exit()

print("No")
