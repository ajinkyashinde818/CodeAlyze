import numpy as np

n = int(input())
a = np.array(list(map(int, input().split())), dtype=np.int64)

if np.sum([a < 0]) % 2 == 0 or np.sum([a == 0]) > 0:
    print(np.sum(np.abs(a)))
else:
    print(np.sum(np.abs(a)) - np.min(np.abs(a)) * 2)
