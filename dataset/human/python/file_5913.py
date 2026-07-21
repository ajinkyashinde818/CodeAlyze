from sys import stdin

n = int(stdin.readline().rstrip())
a, b, c = [[int(x) for x in stdin.readline().rstrip().split()]
           for _ in range(3)]
total = 0
for i in range(len(a)):
    total += b[a[i]-1]
    if (i != len(a) - 1) and (a[i + 1] - a[i] == 1):
        total += c[a[i] - 1]

print(total)
