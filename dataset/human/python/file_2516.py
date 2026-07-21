import numpy as np
D, G=list(map(int, input().split()))
p_c = []
for _ in range(D):
    p_c.append( list(map(int, input().split())) )

min_num = -1
for i in range( 2**D ):
    incomp = -1
    temp_score = 0
    temp_num   = 0
    for j in range(D):
        if i>>j & 1:
            temp_score += 100*(j+1)*p_c[j][0] + p_c[j][1]
            temp_num   += p_c[j][0]

    num=0
    if temp_score < G:
        diff = G-temp_score
        for j in reversed( range(D) ):
            if not i>>j & 1:
                while 100*(j+1)*num<diff:
                    num += 1
                if num < p_c[j][0]:
                    temp_num += num
                else:
                    temp_num = np.inf
                break

    if min_num < 0 or min_num > temp_num:
        min_num = temp_num
print(min_num)
