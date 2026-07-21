def dfs(i, sum, cnt, memo):
    if i == d + 1:
        if sum >= g:
            tmp.append(cnt)
        else:
            cnt += min(p_lst[max(memo) - 1], -(-(g - sum) // (max(memo) * 100)))
            if sum + min(p_lst[max(memo) - 1], -(-(g - sum) // (max(memo) * 100))) * max(memo) * 100 >= g:
                tmp.append(cnt)
        
    else:
        dfs(i + 1, sum + 100 * i * p_lst[i - 1] + c_lst[i - 1], cnt + p_lst[i - 1], memo)
        dfs(i + 1, sum, cnt, memo + [i])

d, g = map(int, input().split())
p_lst = []
c_lst = []
tmp = []
for i in range(d):
    p, c = map(int, input().split())
    p_lst.append(p)
    c_lst.append(c)


dfs(1, 0, 0, [])
print(min(tmp))
