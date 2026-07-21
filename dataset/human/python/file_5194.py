N,M = map(int,input().split())
one = []
nnn = []
for i in range(M):
    ai,bi = map(int,input().split())
    if ai == 1:
        one.append(bi)
    if bi == N:
        nnn.append(ai)
def bs_left(l, target): # l=sorted, target以上の値をもつ要素のうち一番左のindexを返す
    low, high = 0, len(l)
    while low < high:
        mid = (low+high)//2
        if l[mid] < target:
            low = mid+1
        else:
            high = mid
    if low == len(l):
        return -1
    return low
flag = False
if len(one) == 0 or len(nnn) == 0:
    pass
else:
    nnn.sort()
    for i in range(len(one)):
        if nnn[bs_left(nnn,one[i])] == one[i]:
            flag = True
            break

if flag:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
