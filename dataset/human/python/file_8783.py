from itertools import tee


def pairwise(iterable):
    a, b = tee(iterable)
    next(b, None)
    return zip(a, b)


K, N = map(int, input().split())
A = list(map(int, input().split()))

lengths = [abs(p - q) for p, q in pairwise(A + [A[0] + K])]
sum_length = sum(lengths)
max_length = max(lengths)

print(sum_length - max_length)
