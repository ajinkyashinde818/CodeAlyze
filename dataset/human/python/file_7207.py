from collections import deque


def input_int_list():
    return [int(thing) for thing in input().split(" ")]


S=input()
Q=int(input())
Q_list=[input().split(" ") for i in range(Q)]
hantenness=1
left=[]
right=[]
ans=deque()
ans.extend(list(S))

for Query in Q_list:
    if Query[0]==str(1):
        hantenness*=-1
    else:
        C=Query[2]
        F=int(Query[1])
        if hantenness==1:
            if F==1:
                ans.appendleft(C)
            else:
                ans.append(C)
        else:
            if F==1:
                ans.append(C)
            else:
                ans.appendleft(C)

print("".join(ans) if hantenness==1 else "".join(ans)[::-1])
