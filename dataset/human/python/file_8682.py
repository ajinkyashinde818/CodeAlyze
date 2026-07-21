import numpy as np

k, n = tuple(map(int, input().split()))
a_list = list(map(int, input().split()))

diffs = np.diff(np.array(a_list))
diff_max = max(diffs.max(), a_list[0] + (k - a_list[-1]))

print(k - diff_max)
