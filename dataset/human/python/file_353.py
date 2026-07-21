from sys import stdin

n = int(stdin.readline().rstrip())
li = list(map(int,stdin.readline().rstrip().split()))

point = 0
mi = 10**10
total = 0

for i in li:
    if i < 0:
        point += 1
    mi = min(mi,abs(i))
    total += abs(i)
if point % 2 == 0:
    print(total)
else:
    print(total-mi*2)
