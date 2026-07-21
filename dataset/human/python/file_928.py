import random


def slv(N, C, X, V):
    ans_l = [(0, 0)]
    ans_l_ = [0]
    for x, v in zip(X, V):
        ans_l_.append(max(ans_l_[-1], ans_l[-1][1] + v - x))
        ans_l.append((x, ans_l[-1][1] + v))
    ans_l_.pop(0)
    ans_l.pop(0)

    ans_r = [(0, 0)]
    ans_r_ = [0]
    for x, v in list(zip(X, V))[::-1]:
        ans_r_.append(max(ans_r_[-1], ans_r[-1][1] + v - (C-x)))
        ans_r.append((C-x, ans_r[-1][1] + v))
    ans_r_.pop(0)
    ans_r.pop(0)
        

    # print('p1')

    ans_l_r = []
    for i, a in enumerate(ans_l[:-1], 1):
        # print(ans_r_[N-i-1],  a[1]-2*a[0])
        ans_l_r.append(ans_r_[N-i-1] + a[1]-2*a[0])

    # print('p2')
    ans_r_l = []
    for i, a in enumerate(ans_r[:-1], 1):
        # print(ans_l_[N-i-1],  a[1]-2*a[0])
        ans_r_l.append(ans_l_[N-i-1] + a[1]-2*a[0])

    l = max([x[1]-x[0] for x in ans_l])
    r = max([x[1]-x[0] for x in ans_r])
    lr = 0 if not ans_l_r else max(ans_l_r)
    rl = 0 if not ans_r_l else max(ans_r_l)

    # print(ans_l)
    # print(ans_l_)
    # print(ans_r)
    # print(ans_r_)

    # print(l, r, lr, rl)
    return max(l, r, lr, rl)



def main():
    N, C = list(map(int, input().split()))
    X = []
    V = []
    for _ in range(N):
        x, v = list(map(int, input().split()))
        X.append(x)
        V.append(v)

    # N = 100000
    # C = 1000000000000
    # X = [1]
    # V = [100]
    # for _ in range(N):
    #     X.append(X[-1]+random.randint(1, 10000))
    #     V.append(random.randint(1, 10000))

    print(slv(N, C, X, V))


if __name__ == '__main__':
    main()
