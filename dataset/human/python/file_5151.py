import sys
input = sys.stdin.readline
n, m = map(int, input().split())
fir = []
sec = []

for _ in range(m):
    a, b = map(int, input().split())
    if a == 1:
        fir.append(b)
    elif a == n:
        sec.append(b)
    if b == 1:
        fir.append(a)
    elif b == n:
        sec.append(a)
fir.sort()
sec.sort()
flag = True
for i in fir:
    j = 0
    while flag and sec:
        if i > sec[j]:
            del sec[j]
        elif i == sec[j]:
            print("POSSIBLE")
            flag = False
        else:
            break
if flag == True:
    print("IMPOSSIBLE")
