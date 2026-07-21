from collections import deque
S = input()
ans = deque(S)
Q = int(input())
rev = False
for i in range(Q):
    a_list = input().split()
    if a_list[0] == "1":
        if rev == True:
            rev = False
        else:
            rev = True
    elif (a_list[1] == "1" and rev == False) or (a_list[1] == "2" and rev == True):
        ans.appendleft(a_list[2])
    else:
        ans.append(a_list[2])
if rev:
    ans.reverse()
ans = "".join(ans)
print(ans)
