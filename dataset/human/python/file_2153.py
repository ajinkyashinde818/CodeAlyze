MOD = 1000000007
from collections import Counter
from functools import reduce

if __name__ == '__main__':
    n = int(input())
    s = input()
    counter = Counter(s)
    print(reduce(lambda x, y: (x * y) % MOD, (x + 1 for x in counter.values())) - 1)
