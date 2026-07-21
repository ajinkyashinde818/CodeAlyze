from collections import deque
def solve():
    S = input()
    S = deque(S)
    Q = int(input())

    isReversed = False
    for i in range(Q):
        query = list(input().split())
        T = int(query[0])
        if T == 1:
            if isReversed:
                isReversed = False
            else:
                isReversed = True
        if T == 2:
            F = int(query[1])
            C = query[2]
            # 先頭
            if (isReversed and F == 2) or (not isReversed and F == 1):
                S.appendleft(C)
            # 末尾
            else:
                S.append(C)
        
    ans = ""
    if isReversed:
        ans = list(S)[::-1]
    else:
        ans = list(S)
        
    print("".join(ans))

if __name__ == '__main__':
    solve()
