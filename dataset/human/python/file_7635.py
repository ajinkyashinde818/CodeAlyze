from collections import deque

def solve():
    S = input()
    Q = int(input())
    length = len(S)
    reverse = False
    first,last = deque([]),deque([])
    
    for _ in range(Q):
        query = input().split()
        if len(query) == 1:
            reverse = reverse^1
            first,last = last,first
        else:
            T,F,C = query
            T = int(T)
            F = int(F)
            if F == 1:
                if reverse:
                    first.append(C)
                else:
                    first.appendleft(C)
            else:
                if reverse:
                    last.appendleft(C)
                else:
                    last.append(C)
                
            length += 1
    
    if length == 1:
        print(S)
    else:
        first = list(first)
        last = list(last)
        first = first[::-1] if reverse else first
        mid = list(S)[::-1] if reverse else list(S)
        last = last[::-1] if reverse else last
        # print(reverse,first,mid,last)
        print(''.join(first+mid+last))
        
solve()
