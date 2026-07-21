from collections import deque


def resolve():
    S=deque(list(input()))
    Q=int(input())
    querys=[input() for i in range(Q)]
    rev=False
    for qq in querys:
        if qq=="1":
            rev = not rev
            continue
        _,f,c=qq.split()
        if rev==False and f=="1":
            S.appendleft(c)
        elif rev == True and f=="1":
            S.append(c)
        elif rev==False and f=="2":
            S.append(c)
        else:
            S.appendleft(c)
    ans=list(S)
    if rev ==False:
        print("".join(ans))
    else:
        print("".join(reversed(ans)))



    


if __name__ == "__main__":
    resolve()
