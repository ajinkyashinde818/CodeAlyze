from sys import stdin
import numpy as np
N = int(stdin.readline().rstrip())
data = [int(x) for x in stdin.readline().rstrip().split()]
ans = 10**18
lcums = np.cumsum(data)
rcums = list(reversed(np.cumsum(list(reversed(data)))))
for i in range(0,N-1):
    ans = min(ans,abs(lcums[i]-rcums[i+1]))
print(ans)
