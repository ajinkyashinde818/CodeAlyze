from collections import deque

s = input()
q = int(input())
ans = deque(s)

flag = False

for i in range(1, q+1):
    a = input().split()
    if len(a) == 1:
        flag = not flag
    else:
        _, f, c = a
        if (f == "1" and flag == False) or (f == "2" and flag == True):
            ans.extendleft(c)
        elif (f == "1" and flag == True) or (f == "2" and flag == False):
            ans.extend(c)
        else:
            print("fac")
            exit(1)

if flag:
    print("".join(list(ans)[::-1]))
else:
    print("".join(ans))
