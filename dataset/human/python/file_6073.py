from sys import stdin

n = int(stdin.readline().rstrip())
a = [int(x) for x in stdin.readline().rstrip().split()]
b = [int(x) for x in stdin.readline().rstrip().split()]
c = [int(x) for x in stdin.readline().rstrip().split()]

score = 0
ex = 0
for i in a:
    score += b[i-1]
    if ex != 0 and i == ex+1:
        score += c[ex-1]
    ex = i

print(score)
