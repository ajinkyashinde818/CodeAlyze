from collections import Counter
N = int(input())
As = input().split()
Bs = input().split()

allct = Counter(As + Bs)
if allct.most_common(1)[0][1] > N:
    print('No')
    exit()

lastInA = {}
firstInB = {}

for i, a in enumerate(As):
    lastInA[a] = i

for i, b in enumerate(Bs):
    if b not in firstInB:
        firstInB[b] = i

offset = 0
for k, v in lastInA.items():
    if k not in firstInB:
        continue
    tmp = v - firstInB[k] + 1
    offset = offset if offset > tmp else tmp

print('Yes')
print(' '.join(Bs[-offset:] + Bs[:-offset]))
