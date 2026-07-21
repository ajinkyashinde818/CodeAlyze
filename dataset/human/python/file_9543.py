from sys import stdin


if __name__ == "__main__":
    _in = [_.rstrip() for _ in stdin.readlines()]
    N, K = list(map(int,_in[0].split(' ')))  # type:list(int)
    A_arr = [0]+list(map(int,_in[1].split(' ')))  # type:list(int)
    # vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    period = N
    visit = [False] * (N+1)
    order = []
    next_visit = 1
    for i in range(N):
        order.append(next_visit)
        visit[next_visit] = True
        next_visit = A_arr[next_visit]
        if visit[next_visit]:
            period = len(order[order.index(next_visit):])
            ofst = len(order[:order.index(next_visit)])
            break
    if K<=ofst:
        cnt = order[K]
    else:
        tmp = order[order.index(next_visit):]
        cnt = tmp[(K-ofst)%period]
    # ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    print(cnt)
