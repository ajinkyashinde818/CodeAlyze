import math
D,G = map(int,input().split())
s_max = []
pn = []
for i in range(1,D+1):
    p,c = map(int,input().split())
    s_max.append(100*i*p+c)
    pn.append(p)
num_all = sum(pn)
for i in range(2<<D):
    a = []
    for j in range(D):
        a.append(i%2)
        i = i//2
    s = sum([s_max[i] for i in range(D) if a[i] == 1])
    if 0 in a:
        m = max([i for i in range(D) if a[i] == 0])
        num = math.ceil((G-s)/(100*(m+1)))
        if G> s and num <= pn[m]:
            num_all = min(num_all,sum([pn[i] for i in range(D) if a[i] == 1])+num)
        elif G <= s:
            num_all = min(num_all,sum([pn[i] for i in range(D) if a[i] == 1]))
print(num_all)
