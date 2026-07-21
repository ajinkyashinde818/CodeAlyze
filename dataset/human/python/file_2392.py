import math 
D,G = map(int, input().split())
pc = [list(map(int, input().split())) for i in range(D)]

ans = 10000
for i in range(2**D):
    count = 0
    no = []
    s = 0
    for j in range(D):
        if (i >> j) & 1:
            count += pc[j][0]
            s += 100*(j+1)*pc[j][0] + pc[j][1]
        else:
            no.append(j)
    if s >= G:
        ans = min(ans, count)
    else:
        for j in no:
            t = s + 100*(j+1)*(pc[j][0] -1)
            if t >= G:
                ans = min(ans, count + math.ceil((G-s) /(100*(j+1))))
print(ans)
