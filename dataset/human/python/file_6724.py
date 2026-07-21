def RevFlag(flag):
    if flag:
        return False
    else:
        return True

def main():
    from collections import deque
    S = input()
    d = deque()
    for s in S:
        d.append(s)
    N = int(input())
    rev = False

    for i in range(N):
        Q = [i for i in input().split()]
        if len(Q) == 1:
            rev = RevFlag(rev)
        else:
            F = int(Q[1])
            C = Q[2]
            if F == 1:
                if rev:
                    d.append(C)  # 末尾
                else:
                    d.appendleft(C)  # 先頭
            else:
                if rev:
                    d.appendleft(C)  # 先頭
                else:
                    d.append(C)  # 末尾
    if rev:
        d = ''.join(list(reversed(d)))
    else:
        d = ''.join(list(d))
    print(d)


if __name__ == '__main__':
    main()
