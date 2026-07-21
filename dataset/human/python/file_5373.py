from sys import stdin
N,M = [int(x) for x in stdin.readline().rstrip().split()]
data = []
for _ in range(M):
    data.append([int(x) for x in stdin.readline().rstrip().split()])
shima = set()

flag = False
for i in sorted(data):
    if i[0] == 1:
        shima.add(i[1])
    if (i[1] == N) and (i[0] in shima):
        flag = True
        break

if flag:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
