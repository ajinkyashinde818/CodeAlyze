import numpy as np
N = int(input())
list1 = list(map(int, input().split()))

sum1 = 0
for i in list1:
    if(i<0):
        sum1 += 1

nl1 = np.array(list1)
np.abs(nl1)
if(sum1%2 == 0):
    a = sum(np.abs(nl1))
else:
    a = sum(np.abs(nl1))-2*min(np.abs(nl1))

print(a)
