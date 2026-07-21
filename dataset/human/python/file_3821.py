from collections import defaultdict

N = int(input())
if N == 1:
    print(0)
    exit()

index = int(pow(N, 0.5) + 1)
ans = []
for i in range(2, index):
    while N % i == 0:
        N //= i
        ans.append(i)

if N != 1:
    ans.append(N)

if ans == []:
    print(1)
    exit()
d = defaultdict(int)
for i in ans:
    d[i] += 1

sosuLst = []
for v, c in d.items():
    cnt = 1
    while c > 0:
        c -= cnt
        cnt += 1
        if c != 0 and c < cnt:
            sosuLst.append(v ** cnt)
            break
        else:
            sosuLst.append(v ** (cnt - 1))

print(len(set(sosuLst)))
