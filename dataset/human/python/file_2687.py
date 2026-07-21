import itertools
import math
import sys

d, g = [int(x) for x in input()[:-2].split()]
pc = [[int(x) for x in input()[:-2].split()] for _ in range(d)]

def search(choice):
    total = sum(((i + 1) * p + c) * chosen for i, ((p, c), chosen) in enumerate(zip(pc, choice)))
    count = sum(p * chosen for (p, _), chosen in zip(pc, choice))

    if total < g:
        partial = d - list(reversed(choice)).index(0)
        partial_count = math.ceil((g - total) / partial)
        if partial_count <= pc[partial - 1][0]:
            count += partial_count
        else:
            count = sys.maxsize

    return count

print(min(search(choice) for choice in itertools.product(*([0, 1] for _ in range(d)))))
