import collections

N,K = map(int,(input().split()))
a = list(map(int,(input().split())))
a.insert(0,-1)

now = 1
visit = [1]
again = collections.defaultdict(lambda:-1)
again[1] = 0
c = 0

for step in range(1,N+1):
    visit.append(a[now])
    if again[ a[now] ] == -1:
        again[ a[now] ] = step
    else:
        c += 1
        if c == 1:
            loop = a[now]
            loop_step = step
    now = a[now]

re = loop_step - again[loop]

if K <= again[loop]:
    print(visit[K])
else:
    tmp = again[loop]
    for key in again.keys():
        again[key] -= tmp
    amari = (K-tmp)%re
    for key in again.keys():
        if again[key] == amari:
            print(key)

"""
print(visit)
print(again[loop])
print(loop)
print(again)
print(loop_step)
print(re)
"""
