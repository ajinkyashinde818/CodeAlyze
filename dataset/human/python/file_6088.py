from sys import stdin
n = int(stdin.readline().rstrip())
a = list(map(int, stdin.readline().rstrip().split()))
b = list(map(int, stdin.readline().rstrip().split()))
c = list(map(int, stdin.readline().rstrip().split()))

res = 0
predish = -999
for dish in a:
    res += b[dish - 1]
    if dish - predish == 1:
        res += c[predish - 1]
    predish = dish

print(res)
