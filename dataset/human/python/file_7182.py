from collections import deque
S = input()
Q = int(input())
left = deque()
right = deque()
rotate = 1
for i in range(Q):
    n = [str(i) for i in input().split()]
    if n[0] == "1":
        rotate *= -1
    else:
        if n[1] == "1":
            if rotate == 1:
                left.appendleft(n[2])
            else:
                right.append(n[2])
        else:
            if rotate == 1:
                right.append(n[2])
            else:
                left.appendleft(n[2])
left = list(left)
right = list(right)
ans = "".join(left)
ans += S
ans += "".join(right)
if rotate == 1:
    print(ans)
else:
    print(ans[::-1])
