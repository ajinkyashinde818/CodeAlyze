from collections import deque

s = input()
q = int(input())
isInversed = False
front = deque()
back = deque()
for _ in range(q):
    inp =  list(input().split())
    if inp[0] == '1':
        isInversed = not isInversed
    else:
        if inp[1] == '1':
            if not isInversed:
                front.appendleft(inp[2])
            else:
                back.append(inp[2])
        else:
            if not isInversed:
                back.append(inp[2])
            else:
                front.appendleft(inp[2])

front_str = ''.join(front)
back_str = ''.join(back)
ans = front_str + s + back_str

if not isInversed:
    print(ans)
else:
    print(ans[::-1])
