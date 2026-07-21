import numpy as np

D,G = map(int, input().split())
P = []
C = []

for i in range(D):
    p,c = map(int,input().split())
    P.append(p)
    C.append(c)

cnt = np.zeros(D,dtype=int)
P = np.array(P)
C = np.array(C)

ans = sum(P)
cnt_tar = 0

ind_list = np.arange(D)

for bit_seed in range(2**D):

    s_bit = (format(bit_seed, '#016b'))[::-1]
    bit_list = np.array(list(s_bit[:D]),dtype=int)

    cnt = P*bit_list
    num_base = np.sum(cnt)

    point_base_array = (P * (ind_list+1) * 100 + C) * bit_list
    point_base = np.sum(point_base_array)
#    print(point_base_array)

    if point_base >= G:
        num = num_base
        ans = min(ans,num)
    elif num_base > ans:
        continue
    else:
        for i,bit in enumerate(bit_list):
            if bit == 0:
                tar = i

        point_max = point_base + P[tar]*(tar+1)*100 + C[tar]
        if point_max >= G:

            tar_min = (G-point_base) // ((tar+1)*100)
            point = point_base + P[tar]*(tar+1)*100*tar_min

            if point < G:
                tar_min += 1

            if tar_min < P[tar]:
                num = num_base + tar_min
            else:
                num = num_base + P[tar]
            ans = min(ans,num)

print(ans)
