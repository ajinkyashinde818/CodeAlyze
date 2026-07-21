from collections import deque

S = deque(input())
Q = int(input())
count = 0
for i in range(Q):
    input_list = input().split()
    if input_list[0] == "1":
        count += 1
        continue

    if count % 2 == 0:  # even
        if input_list[1] == "1":
            S.appendleft(input_list[2])
        else:
            S.append(input_list[2])
    else:
        if input_list[1] == "2":
            S.appendleft(input_list[2])
        else:
            S.append(input_list[2])

if count % 2 == 0:
    ans = ''.join(S)
    print(ans)
else:
    S.reverse()
    ans = ''.join(S)
    print(ans)
