def solve():
    from collections import deque
    S = input()
    s = deque(S)
    Q = int(input())
    reverse = False
    for i in range(Q):
        T = input().split()
        if T[0] == '1':
            if reverse:
                reverse = False
            else:
                reverse = True
        else:
            if T[1] == '1' and not reverse:
                s.appendleft(T[2])
            elif T[1] == '1' and reverse:
                s.append(T[2])
            elif T[1] == '2' and not reverse:
                s.append(T[2])
            else:
                s.appendleft(T[2])
    if reverse:
        print(''.join(s)[::-1])
    else:
        print(''.join(s))

if __name__ == "__main__":
    solve()
