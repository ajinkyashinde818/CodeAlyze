import math
D, G = [int(i) for i in input().split()]
data_ls = list()
for i in range(D):
    data_ls.append([int(i) for i in input().split()])
ps, cs = zip(*data_ls)

def search(cnt, sum, flg, rest_max):
    if sum >= G:
        return cnt
    if flg == len(data_ls):
        if sum + (ps[rest_max] - 1) * 100 * (rest_max + 1) >= G:
            return cnt + math.ceil((G - sum) / (100 * (rest_max+1)))
        else:
            return 1e9
    cnt = min(search(cnt + ps[flg], sum + (ps[flg] * 100 * (flg+1) + cs[flg]), flg + 1, rest_max),
              search(cnt, sum, flg + 1, flg))
    return cnt

print(search(0,0,0,0))
