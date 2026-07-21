import numpy as np
k,n=map(int,input().split())
a=np.array(list(map(int,input().split())))

a_diff=np.diff(a)
a_diff2=(k - a[n-1])+a[0]
diff_max=np.max(np.append(a_diff,a_diff2))
print(k-diff_max)
