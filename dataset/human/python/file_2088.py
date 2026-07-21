from functools import reduce
N = int(input())
DIV = 10**9 + 7
S = {chr(i): 0 for i in range(ord('a'), ord('z') + 1)}
for c in input():
    S[c] += 1
print(reduce(lambda acc, n: acc * (n + 1) % DIV, S.values(), 1) - 1)
