import sys

read = sys.stdin.read
readline = sys.stdin.readline

N, K, *A = map(int, read().split())
A = [i - 1 for i in A]

check = [False] * N
seq = []
here = 0
while True:
    if K == 0:
        print(here + 1)
        exit()
    if check[here]:
        break
    seq.append(here)
    check[here] = True
    here = A[here]
    K -= 1

seq = seq[seq.index(here):]
circ = len(seq)
K %= circ
print(seq[K] + 1)
