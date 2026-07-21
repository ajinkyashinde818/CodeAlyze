from collections import deque

def reversedeq(deq):
    newdeq = deque()
    for _ in range(len(deq)):
        c = deq.pop()
        newdeq.append(c)
    
    return newdeq


S = deque(list(input()))
Q = int(input())
reverse_state = False

for _ in range(Q):
    Query = [x for x in input().split()]
    if len(Query) == 1:
        reverse_state = reverse_state ^ 1
    else:
        if reverse_state:
            if Query[1] == '1':
                S.append(Query[2])
            else:
                S.appendleft(Query[2])
        else:
            if Query[1] == '1':
                S.appendleft(Query[2])
            else:
                S.append(Query[2])

if reverse_state:
    S = reversedeq(S)

print("".join(S))
