import numpy as np

K,N=list(map(int, input().split()))
a = np.array(list(map(int, input().split())))
diff_a=np.diff(a,n=1)
max_index=np.argmax(diff_a)
temp_max=diff_a[max_index]
last_first=K-(a[-1]-a[0])
if temp_max>last_first:
  print(int(K-temp_max))
else:
  print(int(K-last_first))
