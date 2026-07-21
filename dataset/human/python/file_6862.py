from collections import deque

S = input()
Q = int(input())

S = deque(S)
reverse = False

for _ in range(Q):
    query = input()
    if query[0] == '1':
        reverse = not reverse
    elif query[0] == '2':
        _, F, C = query.split()
        if F == '1':
            if reverse:
                S.append(C)
            else:
                S.appendleft(C)
        elif F == '2':
            if reverse:
                S.appendleft(C)
            else:
                S.append(C)
            
result = ''.join(S)
if reverse:
    result = result[::-1]
print(result)
