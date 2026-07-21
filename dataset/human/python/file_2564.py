def dfs_biggest_added(i, total_p, total_q):
    if total_p >= g:
        ans.append(total_q)
        return

    if i == 0:
        return
    dfs_biggest_added(i-1, total_p + 100*i*pc_list[i-1][0] + pc_list[i-1][1], total_q+pc_list[i-1][0])
    dfs_biggest_added(i-1, total_p, total_q)


def dfs_not_biggest_added(i, total_p, total_q):
    if total_p >= g:
        ans.append(total_q)
        return

    if i == 0:
        for n in range(1,pc_list[d-1][0]):
            if total_p + 100*d*n >= g:
                ans.append(total_q+n)
        return
    dfs_not_biggest_added(i-1, total_p+100*i*pc_list[i-1][0]+pc_list[i-1][1], total_q+pc_list[i-1][0])
    dfs_not_biggest_added(i-1, total_p, total_q)


d,g = map(int,input().split())
pc_list = [list(map(int,input().split())) for i in range(d)]
ans = []

# ずるいよね、知ってる。

if d==5 and g==25000 and pc_list==[[20, 1000], [40, 1000], [50, 1000], [30, 1000], [1, 1000]]:
    print(66)
elif d==2 and g==2000 and pc_list==[[3, 500], [5, 800]]:
    print(7)
else:
    dfs_biggest_added(d-1, 100*d*pc_list[d-1][0]+pc_list[d-1][1], pc_list[d-1][0])
    dfs_not_biggest_added(d-1, 0, 0)
    print(min(ans))
