import numpy as np

n = int(input())
an = np.array([int(i) for i in input().split(" ")])
suma = 0
suma = np.sum(an <= 0)
minus = np.empty(0)
if suma % 2 == 0:
    print(np.sum(np.abs(an)))
else:
    print(int(np.sum(np.abs(an)) - 2 * np.min(np.abs(an))))
