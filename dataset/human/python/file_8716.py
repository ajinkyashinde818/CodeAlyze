import math

KN = list(map(int, input().split()))
A = list(map(int, input().split()))

path = 0
lastPosition = 0

for i in range(KN[1]):
    if (i == 0):
        path = KN[0] + A[0] - A[KN[1] - 1]
        lastPosition = A[0]
    else:
        currentPosition = A[i]
        if (path < currentPosition - lastPosition):
            path = currentPosition - lastPosition
        lastPosition = currentPosition

print(KN[0] - path)
