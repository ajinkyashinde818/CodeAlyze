from collections import deque
s = input()
q = int(input())
right_side = deque()
left_side = deque()
is_reversed = False
for i in range(q):
    l = list(input().split())
    if l[0] == '1':
        is_reversed = not is_reversed
    else:
        if l[1] == '2':
            if is_reversed == False:
                right_side.append(l[2])
            else:
                left_side.appendleft(l[2])
        else:
            if is_reversed == False:
                left_side.appendleft(l[2])
            else:
                right_side.append(l[2])
ans = ''.join([''.join(left_side),s ,''.join(right_side)])
if is_reversed :
    ans = ans[::-1]
print(ans)
