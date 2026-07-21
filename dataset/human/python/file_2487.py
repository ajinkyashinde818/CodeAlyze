from sys import stdin
import math
d,g = map(int,stdin.readline().rstrip().split())
PC = [list(map(int,stdin.readline().rstrip().split())) for _ in range(d)]
mi = 10**10
for i in range(2**d):
    point = 0
    count = 0
    not_all = []
    for j in range(d):
        if (i >> j) & 1:
            point += (j+1)*PC[j][0]*100+PC[j][1]
            count += PC[j][0]
        else:
            not_all.append(j)
    if point < g:
        #すべて取り出す以外の問題番号のうち最大のもの
        saidai = not_all[-1]
        need = math.ceil((g-point)/((saidai+1)*100))
        if need >= PC[saidai][0]:
            continue
        else:
            count += need
    mi = min(mi,count)
print(mi)
