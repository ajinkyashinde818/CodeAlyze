def a_colorful_subsequence(N, S):
    from collections import Counter
    from functools import reduce
    from operator import mul
    return (reduce(mul, map(lambda x: x + 1, Counter(S).values())) - 1) % (10**9 + 7)

N = int(input())
S = input()
print(a_colorful_subsequence(N, S))
