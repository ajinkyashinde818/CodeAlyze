import numpy as np

n = int(input())
a = np.array(list(map(int, input().split())))

suml = np.cumsum(a)
sumr = np.cumsum(a[::-1])[::-1]
diff = np.abs(sumr[1:] - suml[:-1])

print(min(diff))
