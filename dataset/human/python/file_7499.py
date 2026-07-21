from collections import deque
def main():
    S = input()
    S = deque([c for c in S])
    Q = int(input())
    rvCt = 0

    for _ in range(Q):
        query = input().split()
        if query[0] == '1':
            rvCt += 1
        else:
            doReverse = False
            if rvCt % 2 == 1:
                doReverse = True

            if query[1] == '1':
                if doReverse:
                    S.append(query[2])
                else:
                    S.appendleft(query[2])
            else:
                if doReverse:
                    S.appendleft(query[2])
                else:
                    S.append(query[2])

    if rvCt % 2 == 1:
        S.reverse()
    
    print(''.join(S))

main()
