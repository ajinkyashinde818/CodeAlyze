import numpy as np

k, n = map(int,input().split())
a = np.array(list(map(int, input().split())))
diff = a[1:] - a[:-1]
diff = np.append(diff, k - a[-1] + a[0])
if np.argmax(diff) == len(a) - 1:
    print(a[-1] - a[0])
else:
    print(k - a[np.argmax(diff) + 1] + a[np.argmax(diff)])
