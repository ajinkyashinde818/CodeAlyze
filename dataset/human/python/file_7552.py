from sys import stdin
from collections import deque
def main():
    readline=stdin.readline
    S=readline().strip()
    d=deque(S)

    Q=int(readline())
    mode=1
    count=0
    for i in range(Q):
        li=readline().split()
        if li[0]=="1":
            mode+=1
            mode%=2
            count+=1
        else:
            o=li[1]
            c=li[2]
            if mode==1 and o=="1":
                d.appendleft(c)
            elif mode==0 and o=="1":
                d.append(c)
            elif mode==1 and o=="2":
                d.append(c)
            elif mode==0 and o=="2":
                d.appendleft(c)
    res=list(d)
    if count%2==1:
        res=res[::-1]
    print("".join(res))
if __name__=="__main__":
    main()
