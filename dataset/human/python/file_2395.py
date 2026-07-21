import itertools
import math

D, G = map(int, input().split())
p, c = [0]*D, [0]*D
for i in range(D):
    p[i], c[i] = map(int, input().split())

ls = []
for i in itertools.product([0, 1], repeat=D):
    sum = 0
    ans = 0
    for j, x in enumerate(i):
        if x == 1:
            sum += c[j] + (100*(j+1))*p[j]
            ans += p[j]
    if sum >= G:
        ls.append(ans)
    else:
        for j, x in enumerate(i[::-1]):
            if x != 1:
                if math.ceil((G-sum)/(100*(D-j))) <= p[D-1-j] - 1:
                    ans += math.ceil((G-sum)/(100*(D-j)))
                    ls.append(ans)
                    break
                else:
                    sum += (100*(D-j))*(p[D-1-j] - 1)
                    ans += p[D-1-j] - 1
print(min(ls))
