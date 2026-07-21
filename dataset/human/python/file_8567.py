import numpy as np

k, n = map(int, input().split())
l = list(map(int, input().split()))
a = np.array(l)
b = np.delete(np.append(a,k+a[0]), 0)

sa = b-a
sa_dash = np.delete(sa, np.argmax(sa))
print(np.sum(sa_dash))
