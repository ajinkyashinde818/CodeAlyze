def d():
    from collections import deque
    S = deque(str(input()))
    Q = int(input())
    rvs = False

    for i in range(Q):
        q = list(input().split())

        if q[0] == '1':
            rvs = not rvs
        elif q[0] == '2':
            if q[1] == '1':
                if rvs:
                    S.append(q[2])
                else:
                    S.appendleft(q[2])
            elif q[1] == '2':
                if rvs:
                    S.appendleft(q[2])
                else:
                    S.append(q[2])
            else:
                raise ValueError(
                    'F({}) is {}, which is invalid!'.format(i, q[1]))
        else:
            raise ValueError('T({}) is {}, which is invalid!'.format(i, q[0]))

    if rvs:
        ans = list(S)[::-1]
    else:
        ans = list(S)
    print(''.join(ans))


##########
if __name__ == "__main__":
    d()
