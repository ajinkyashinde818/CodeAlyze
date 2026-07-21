from collections import deque
s=input()
q=int(input())
Q=[input().split() for _ in range(q)]
word_l,word_r=deque([]),deque([])

flag=1
for i in Q:
    if i[0]=="1" and flag==1:
        flag=0
    elif i[0]=="1" and flag==0:
        flag=1

    elif i[0]=="2":
        num,f,c=i
        if f=="1" and flag==1:
            word_l.appendleft(c)
        elif f=="1" and flag==0:
            word_r.append(c)
        elif f=="2" and flag==1:
            word_r.append(c)
        elif f=="2" and flag==0:
            word_l.appendleft(c)

word_r="".join(word_r)
word_l="".join(word_l)
if flag==1:
    print(word_l+s+word_r)
else:
    print(word_r[::-1]+s[::-1]+word_l[::-1])
