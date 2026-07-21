from collections import Counter, deque

(N,) = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

freqA = Counter(A)
freqB = Counter(B)
for k in freqA.keys() & freqB.keys():
    if freqA[k] + freqB[k] > N:
        print("No")
        exit()

B = deque(B)
while True:
    rotate = 0
    for i in range(N):
        while A[(i + rotate) % N] == B[i]:
            rotate += 1
    bad = False
    B.rotate(rotate)
    for a, b in zip(A, B):
        if a == b:
            bad = True
    if not bad:
        break

print("Yes")
print(" ".join(map(str, B)))
