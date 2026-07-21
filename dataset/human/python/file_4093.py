import math

def fact(x, k):
    if x % (k ** (A[-1] + 1)) == 0:
        A[-1] += 1
        return fact(x // (k ** (A[-1])), k)
    for i in range(k, int(math.sqrt(x)) + 1):
        if x % i == 0:
            if i != k:
                A.append(1)
            return fact(x // i, i)
    if x > k:
        A.append(1)

N = int(input())
A = [0]
fact(N, 2)
print(sum(A))
