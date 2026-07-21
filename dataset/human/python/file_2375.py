d,g = map(int, input().split())
l = []
for i in range(d):
    l.append(list(map(int,input().split())))
from itertools import *
ans=10**9
for tmp in list(product([True,False], repeat=d)):
    nokori=g
    rest=[]

    solved=0
    for comp in range(d):
        if tmp[comp]:
            nokori -= l[comp][1]
            solved += l[comp][0]
            nokori -= l[comp][0]*100*(comp+1)
        else:
            for i in range(l[comp][0]):
                rest.append((comp+1) * 100)
    if nokori > 0:
        rest.sort()
        rest.reverse()

        for i in range(len(rest)):
            nokori-=rest[i]
            solved+=1
            if nokori <=0:
                break
    if ans > solved:
        ans=solved
print(ans)
