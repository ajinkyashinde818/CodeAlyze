import sys
from collections import deque

def solve():
    input = sys.stdin.readline
    S = list(input().strip("\n"))
    q = deque()
    for i, s in enumerate(S): q.append(s)
    state = 0 #0の時初期の順番
    Q = int(input())
    for _ in range(Q):
        query = list(input().strip("\n").split())
        if query[0] == "1": state ^= 1
        else:
            f = int(query[1]) % 2
            c = query[2]
            if state ^ f == 1: q.appendleft(c)
            else: q.append(c)
    Ans = ""
    if state == 0:
        while q: Ans += q.popleft()
    else:
        while q: Ans += q.pop()
    print(Ans)
    
    

    return 0

if __name__ == "__main__":
    solve()
