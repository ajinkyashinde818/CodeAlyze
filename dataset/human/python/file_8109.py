from itertools import product

K, S = map(int, input().split(' '))
zero_to_k = tuple(range(K + 1))
max_k = min(K, S) + 1

print(len([0 for x, y in product(range(max_k), range(max_k)) if 0 <= S - (x + y) <= K]))
