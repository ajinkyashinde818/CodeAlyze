from collections import deque
S = deque(input().rstrip())
Q=int(input())
cnt=True
for i in range(Q):
    query_list=input().split()
    if query_list[0] == "1":
        cnt=(cnt==False)
    else:
        if cnt:
            if query_list[1] == "1":
                S.appendleft(query_list[2])
            else:
                S.append(query_list[2])
        else:
            if query_list[1] == "1":
                S.append(query_list[2])
            else:
                S.appendleft(query_list[2])
if cnt:
    print("".join(S))
else:
    print("".join(reversed(S)))
