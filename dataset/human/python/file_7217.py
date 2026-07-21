from collections import deque

s=input()
q=int(input())
count=0 #何回反転があるか
ss=deque(s)
flag=True #通常状態
for i in range(q):
    info=input()
    if info[0]=="1":
        count+=1
        if flag:
            flag=False
        else:
            flag=True
    else:
        _,f,c=info.split()
        if flag:
            if f=="1":
                ss.appendleft(c)
            else:
                ss.append(c)
        else: #反転状態
            if f=="1":
                ss.append(c)
            else:
                ss.appendleft(c)
ans="".join(ss)
print(ans if count%2==0 else ans[::-1])
