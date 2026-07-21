from collections import deque
s = list(input())
ans = deque(s)
q = int(input())
check = 1
for i in range(q):
    a = list(input().split())
    if a[0] == "1":
        check *= -1
    else:
        if a[1] == "1":
            if check == 1:
                ans.appendleft(a[2])
            else:
                ans.append(a[2])
        else:
            if check == 1:
                ans.append(a[2])
            else:
                ans.appendleft(a[2])
    
ans = list(ans)
if check==1:
    print(*ans,sep="")
else:
    ans = ans[::-1]
    print(*ans,sep="")
