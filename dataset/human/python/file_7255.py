start = []
end = []

def query1(b):
    return not b

def query2(F, C, string, b):
    if (F == '1' and b) or (F == '2' and not b):
        start.append(C)
        return C + string
    else:
        end.append(C)

S = input()
Q = int(input())
direction = True

for i in range(Q):
    Query = input().split()
    if len(Query) == 1:
        direction = query1(direction)
    else:
        query2(Query[1], Query[2], S, direction)

if direction:
    print(''.join(start[::-1]) + S + ''.join(end))
else:
    print(''.join(end[::-1]) + S[::-1] + ''.join(start))
