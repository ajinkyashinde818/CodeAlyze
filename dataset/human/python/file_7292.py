from collections import deque

S = deque(input())
num_of_query = int(input())

is_reverse = False

for _ in range(num_of_query):
    query = list(input().split())
    
    if query[0] == '1':
        is_reverse = not is_reverse
    else:
        if query[1] == '1':
            if is_reverse:
                S.append(query[2])
            else:
                S.appendleft(query[2])

        else:
            if is_reverse:
                S.appendleft(query[2])
            else:
                S.append(query[2])

S = list(S)

if is_reverse:
    S = S[::-1]

print(''.join(S))
