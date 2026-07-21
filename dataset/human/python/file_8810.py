import numpy as np
k, n = map(int, input().split())
a = np.array([int(i) for i in input().split()])
a = np.concatenate([a, [k + a[0]]])
diff_a = np.diff(a)
diff_a = sorted(diff_a)
print(np.sum(diff_a[:-1]))
