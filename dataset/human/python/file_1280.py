import sys

N= int(input())

*A, = map(int, input().split())


S = [0]*(len(A)+1)

for i in range(1, len(S), 1):

    S[i] = S[i-1] + A[i-1]

x = 0
y = 0
min = float('inf')

for i in range(1, N, 1):
    x = S[i]
    y = S[len(S)-1] - S[i]

    if min > abs(x-y):
        min = abs(x-y)
print(min)
