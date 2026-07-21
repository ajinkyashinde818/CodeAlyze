import numpy as np

K, N = [int(element) for element in input().split(" ")]
AList = np.array([int(element) for element in input().split(" ")])
distance = np.diff(AList)
start_end_distance = abs((K - AList[-1]) + AList[0])
distance = np.append(distance, start_end_distance)

print(K - np.max(distance))
