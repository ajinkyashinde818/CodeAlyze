if __name__ == '__main__':
    n, k = map(int, input().split())
    a_list = list(map(int, input().split()))
    
    now = 1
    check = [0] * n
    check[0] = 1
    move = [1]
    for i in range(k):
        now = a_list[now-1]
        move.append(now)
        if check[now-1] == 0:
            check[now-1] = 1
        else: 
            break

    point = (move.index(now))
    roop_len = sum(check) - point

    if k <= sum(check):
        print(move[k])
    else:
        k_ = k - point
        point_ = k_ % roop_len
        print(move[point+point_])
