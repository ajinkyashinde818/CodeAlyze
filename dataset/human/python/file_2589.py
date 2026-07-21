from itertools import product
D, G = map(int, input().split())
l = [tuple(map(int, input().split())) for i in range(D)]
s = [0] * D
ans = float('inf')
for b in product([0,1], repeat=D):
    s = sum([(i+1)*100 * l[i][0] + l[i][1] for i,f in enumerate(b) if f])
    tmp = sum([l[i][0] for i,f in enumerate(b) if f])
    if s < G:
        for i, j in enumerate(reversed(b)):
            if j == 0:
                d = D - i
                k = 0
                if s + 100 * d * (l[d-1][0] - 1 - k) < G:
                    tmp = float('inf')
                    break
                while True:
                    k += 1
                    if s + 100 * d * (l[d-1][0] - 1 - k) < G:
                        break
                tmp += l[d-1][0] - k 
                break
    ans = min(ans, tmp)
print(ans)
