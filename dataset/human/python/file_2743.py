import itertools

D, G = list(map(int, input().split()))
P = [list(map(int, input().split())) for _ in range(D)]

res = 1000000
for i in itertools.product([0, 1], repeat=D):
    cost = 0
    num = 0
    for j in range(len(i)):
        cost += ((j+1)*100*P[j][0]+P[j][1])*i[j]
        num += P[j][0]*i[j]
    #print(i, cost, num, res)
    if cost >= G:
        res = min(res, num)
    else:
        for k in range(len(i)-1, -1, -1):
            if i[k] == 1:
                continue
            for l in range(P[k][0]):
                cost += 100*(k+1)
                num += 1
                if cost >= G:

                    res = min(res, num)
                    break
        else:
            continue
        break

print(res)
