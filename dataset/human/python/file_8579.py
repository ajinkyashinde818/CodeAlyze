import numpy as np
kn = list(map(int,input().split()))
K = kn[0]
N = kn[1]
As = list(map(int,input().split()))

subtract_list_r = np.array([])
subtract_list_l = np.array([])
subtract_list_r = list(subtract_list_r)
subtract_list_l = list(subtract_list_l)

subtract_value_r = 0
subtract_value_l = 0
for i in range(1,N-1):
    subtract_value_r = K-(As[i]-As[i-1])
    subtract_value_l = K-(As[i+1]-As[i])
    subtract_list_r.append(subtract_value_r)
    subtract_list_l.append(subtract_value_l)


subtract_list_r.append(As[N-1]-As[0])
subtract_list_l.append(K-(As[1]-As[0]))
subtract_list_r.append(K-(As[N-1]-As[N-2]))
subtract_list_l.append(abs(As[0]-As[N-1]))
r_min = min(subtract_list_r)
l_min = min(subtract_list_l)

print("{}".format(int(min([r_min,l_min]))))
