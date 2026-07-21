from collections import Counter

N, K = map(int, input().split(' '))
A = tuple(map(int, input().split(' ')))

counter = Counter()

i = 1
while True:
    if counter[i] >= 2:
        break
    counter[i] += 1
    i = A[i - 1]

loop = len([0 for v in counter.values() if v == 2])
to_loop = len([0 for v in counter.values() if v == 1])

if K > to_loop:
    K = to_loop + (K - to_loop) % loop

i = 1
for _ in range(K):
    i = A[i - 1]

print(i)
