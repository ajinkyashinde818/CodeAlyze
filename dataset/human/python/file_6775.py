from collections import deque

def solve():
    S = list(input())
    M = int(input())
    Q = [list(input().split()) for _ in range(M)]
    
    bef = deque([])
    s = deque(S)
    aft = deque([])
    c = 0
    
    for q in Q:
        if q[0] == '1':
            c += 1
        else:
            ad = q[2]
            if q[1] == '1':
                # 先頭
                if c % 2 == 0:
                    bef.appendleft(ad)
                else:
                    aft.append(ad)
            else:
                # 末尾
                if c % 2 == 0:
                    aft.append(ad)
                else:
                    bef.appendleft(ad)

    ans = ''.join(bef) + ''.join(s) + ''.join(aft)
    if c % 2 == 1:
        ans = ans[::-1]

    return ans

print(solve())
