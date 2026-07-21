import numpy as np
K,N=map(int, input().split())
A=list(map(int, input().split()))
A = np.array(A)
distance_list = A[1:N] - A[0:N-1]
distance_list = np.append(distance_list, K-A[N-1]+A[0])
print(K-max(distance_list))
