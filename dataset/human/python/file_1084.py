import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
cnt = [0]*(n+1)
for v in a:
    cnt[v] += 1
for v in b:
    cnt[v] += 1
f = True
for i in range(n+1):
    if cnt[i] > n:
        f = False
        break
if f:
    idx_a = [[] for _ in range(n+1)]
    idx_b = [[] for _ in range(n+1)]
    dic_a = {}
    dic_b = {}
    for i in range(n):
        idx_a[a[i]].append(i)
        idx_b[b[i]].append(i)
        if a[i] in dic_a:
            dic_a[a[i]] += 1
        else:
            dic_a[a[i]] = 1
        if b[i] in dic_b:
            dic_b[b[i]] += 1
        else:
            dic_b[b[i]] = 1
    ans = [None]*n
    rev_cnt = [set() for _ in range(n+1)]
    for i in range(n+1):
        if cnt[i] > 0:
            rev_cnt[cnt[i]].add(i)
    for i in reversed(range(1, n+1)):
        x, y = -1, -1
        if len(rev_cnt[i]) == 2:
            x, y = list(rev_cnt[i])
            if len(idx_a[x]) == 0:
                x, y = y, x
            rev_cnt[i-1] |= rev_cnt[i]
        elif len(rev_cnt[i]) == 1:
            x = list(rev_cnt[i])[0]
            if len(idx_a[x]) > 0:
                rm = None
                for v in dic_b.keys():
                    if dic_b[v] == 0:
                        rm = v
                        continue
                    if v != x:
                        y = v
                        break
                if rm is not None:
                    dic_b.pop(rm)
                s = dic_b[y]
                if y in dic_a:
                    s += dic_a[y]
                rev_cnt[s].remove(y)
                rev_cnt[s-1].add(y)
                rev_cnt[i-1].add(x)
            else:
                y = x
                rm = None
                for v in dic_a.keys():
                    if dic_a[v] == 0:
                        rm = v
                        continue
                    if v != y:
                        x = v
                        break
                if rm is not None:
                    dic_a.pop(rm)
                s = dic_a[x]
                if x in dic_b:
                    s += dic_b[x]
                rev_cnt[s].remove(x)
                rev_cnt[s-1].add(x)
                rev_cnt[i-1].add(y)
        else:
            rm = None
            for v in dic_a.keys():
                if dic_a[v] == 0:
                    rm = v
                    continue
                if v != y:
                    x = v
                    break
            if rm is not None:
                dic_a.pop(rm)
            s = dic_a[x]
            if x in dic_b:
                s += dic_b[x]
            rev_cnt[s].remove(x)
            rev_cnt[s-1].add(x)
            rm = None
            for v in dic_b.keys():
                if dic_b[v] == 0:
                    rm = v
                    continue
                if v != x:
                    y = v
                    break
            if rm is not None:
                dic_b.pop(rm)
            s = dic_b[y]
            if y in dic_a:
                s += dic_a[y]
            rev_cnt[s].remove(y)
            rev_cnt[s-1].add(y)
        ans[idx_a[x].pop(-1)] = y
        idx_b[y].pop(-1)
        dic_a[x] -= 1
        dic_b[y] -= 1
    print("Yes")
    for v in ans:
        print(v, end=" ")
else:
    print("No")
