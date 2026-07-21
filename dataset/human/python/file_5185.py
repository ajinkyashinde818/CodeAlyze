def main():
    n, m = list(map(int, input().split()))
    root_start = []
    root_goal = []
    ans = {}
    for i in range(m):
        li = list(map(int, input().split()))
        if li[0] == 1:
            ans.setdefault(li[1], 0)
            ans[li[1]] += 1
        elif li[1] == n:
            ans.setdefault(li[0], 0)
            ans[li[0]] += 1
    flg = False
    for k in ans:
        if ans[k] >= 2:
            flg = True

    print('POSSIBLE') if flg else print('IMPOSSIBLE')



if __name__ == '__main__':
    main()
