from itertools import combinations
D, G = map(int, input().split())
pc = [[i] + list(map(int, input().split())) for i in range(1,D+1)]
pc2 = [i[1] for i in pc]
res = float("inf")
for n in range(0,D+1):
    for _ in combinations(pc,n):
        memo = pc2[::]
        tmp = 0
        count = 0
        for i,p,c in _:
            tmp += p*100*i + c
            count += p
            memo[i-1] = 0
        if tmp>=G:
            res = min(res,count)
        else:
            for k in range(D-1,-1,-1):
                if (G - (tmp + (k+1)*100*memo[k])) < 0:
                    count += (G-tmp)// ((k+1)*100) 
                    count += 1 if (G-tmp)% ((k+1)*100) !=0 else 0
                    res = min(res,count)
                else:
                    tmp += (k+1)*100*memo[k]
                    count += memo[k]

print(res)
