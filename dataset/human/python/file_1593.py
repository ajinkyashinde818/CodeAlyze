import numpy as np
N, M = map(int, input().split())
A = np.array([int(input().replace("#", "1").replace(".", "0"), base=2) for _ in range(N)], dtype=np.int64)
B = "".join(str(int(input().replace("#", "1").replace(".", "0"), base=2)) for _ in range(M))
mask = (1 << M) - 1
for _ in range(N - M + 1):
    if B in "".join(str(a) for a in A & mask):
        print("Yes")
        break
    A >>= 1
else:
    print("No")
