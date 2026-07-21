from collections import deque
def main():
    S=input()
    S=deque(S)
    Q=int(input())
    flag=1
    for _ in range(Q):
        q=input()
        if q=="1":
            flag*=-1
            continue
        q=list(q.split(" "))
        q[1]=int(q[1])
        if q[1]==2:
            q[1]=-1
        if q[1]*flag <=0:
            S.append(q[2])
        else:
            S.appendleft(q[2])
    if flag==1:
        print("".join(list(S)))
    else:
        print("".join(list(S)[::-1]))
            

main()
