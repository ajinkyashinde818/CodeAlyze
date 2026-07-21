if __name__ == '__main__':
    [n,k] = [int(i) for i in input().split()]
    a = [int(i)-1 for i in input().split()]
    visit = []
    for i in range(n):
        visit.append(False)
    
    i = 0
    l = []
    pos = -1
    ele = -1
    while True:
        if visit[i] == True:
            ele = i
            break
        visit[i] = True
        l.append(i)
        i = a[i]
    
    pos = l.index(ele)
    period = len(l) - pos
    # print(l)
    # print(pos)
    # print(period)

    if pos == 0:
        print(l[k%period]+1)
        exit()

    ans = -1
    if k < len(l):
        ans = l[k]
    else:
        k -= pos
        pos -= 1
        p = k % period
        p+=1
        ans = l[pos+p]
    print(ans+1)
