import numpy as np
K, N = map(int, input().split())

route = list(map(int, input().split()))
diff = np.diff(np.array(route)).tolist()
diff.append(route[0]+K-route[-1])
diff.remove(max(diff))
print(sum(diff))
