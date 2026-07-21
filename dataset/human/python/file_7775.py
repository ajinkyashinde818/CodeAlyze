import collections
n,k,s = input().split()



dq = collections.deque()
max_value = str(10**9)
if int(s) !=10**9:
    for i in range(int(k)):
        dq.append(s)
    for i in range(int(n)-int(k)):
        dq.append(max_value)
    ans = " ".join(list(dq))
    print(ans)
else:
    for i in range(int(k)):
        dq.append(s)
    for i in range(int(n)-int(k)):
        dq.append("1")
    ans = " ".join(list(dq))
    print(ans)
