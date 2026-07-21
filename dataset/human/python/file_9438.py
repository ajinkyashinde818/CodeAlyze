import sys
n, k = [int(i) for i in sys.stdin.readline().split()]
a_s = [int(i)-1 for i in sys.stdin.readline().split()]
cnt = 0
ind = 0
ls = [ind]
last_pos = {0:0}
_set = {ind}
while cnt < k:
    ind = a_s[ind]
    if ind in _set:
        break
    _set.add(ind)
    ls.append(ind)
    cnt += 1
if cnt == k:
    print(ind+1)
else:
    start = ls.index(ind)
    end = cnt+1
    print(ls[start:][(k - cnt) % (end - start)-1]+1)
