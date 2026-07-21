from collections import deque

left = deque()
right = deque()

s = input()
q = int(input())

reverse = False
for i in range(q):
    t_inp = input().split()
    if t_inp[0] == "1":
        reverse = not reverse
    else:
        if t_inp[1] == "1" and reverse:
            right.append(t_inp[2])
        if t_inp[1] == "1" and not reverse:
            left.appendleft(t_inp[2])
        if t_inp[1] == "2" and reverse:
            left.appendleft(t_inp[2])
        if t_inp[1] == "2" and not reverse:
            right.append(t_inp[2])

l_li = list(left)
r_li = list(right)

# print(left)
# print(right)
ans = "".join(l_li)+s+"".join(r_li)

if reverse:
    print(ans[::-1])
else:
    print(ans)
