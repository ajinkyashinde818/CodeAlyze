import math
d, g = map(int, input().split())
p = []
c = []
for _ in range(d):
    a, b  = map(int, input().split())
    p.append(a)
    c.append(b)

min_cnt = 1000
for i in range(2**d):
    cnt = 0
    point = 0
    idx = 0
    for j in range(d):
        if i>>j & 1:
            cnt += p[j]
            point += (j+1)*100*p[j] + c[j]
        else:
            idx = j
    if point>=g and min_cnt>=cnt:
        min_cnt = cnt
    else:
        q = point+(idx+1)*100*(p[idx]-1)
        if q>=g:
            count = max(math.ceil((g-point)/((idx+1)*100)),0)
            cnt += count
            if min_cnt>=cnt:
                min_cnt=cnt
         
print(min_cnt)
