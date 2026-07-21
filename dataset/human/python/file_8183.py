import sys, itertools
def input(): return sys.stdin.readline()
def inpl(): return [int(i) for i in input().split()]

K, S = inpl()
print(sum([0 <= S - x - y <= K for x, y in itertools.product(range(K+1), repeat = 2)]))
