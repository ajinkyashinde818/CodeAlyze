import numpy as np

K, N = map(int, input().split())

a_l = list(map(int, input().split()))

a_l = np.array(a_l)

b_l = np.empty(a_l.shape[0])

b_l[1:] = a_l[:-1]

b_l[0] = a_l[-1]

c_l = a_l - b_l

c_l[0] = K - a_l[-1] + a_l[0]

print(int(K - np.max(c_l)))
