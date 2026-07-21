import sys
input = sys.stdin.readline
N, K = map(int, input().split())
a = list(map(lambda x: int(x) - 1, input().split()))
loop = []
start = 0
index = 0
check = [-1] * N
fin = False
count = 0
while True:
    if check[index] != -1:
        start = check[index]
        break
    else:
        loop.append(index)
        if len(loop) == K + 1:
            print(index + 1)
            sys.exit()
        check[index] = count
        count += 1
        index = a[index]


if (K + 1 - start) % len(loop[start:]) == 0:
    print(loop[-1] + 1)
else:
    print(loop[start + (K + 1 - start) % len(loop[start:]) - 1] + 1)
