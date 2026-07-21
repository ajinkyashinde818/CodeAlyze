def main():
    import numpy as numpy
    import sys
    from collections import deque

    S=sys.stdin.readline().strip()
    Q=int(sys.stdin.readline())
    rv=False
    S=deque(S)
    for i in range(Q):
        qs=sys.stdin.readline().split()
        if int(qs[0])==1:
            rv=(rv+1)%2
        elif int(qs[0])==2:
            if (int(qs[1])-1+rv)%2==0:
                S.appendleft(qs[2])
            elif (int(qs[1])-1+rv)%2==1:
                S.append(qs[2])
            else:
                print('error')
                return
        else:
            print('error')
            return
    
    if rv:
        S=reversed(list(S))
    else:
        S=list(S)

    S="".join(S)
    
    return S

print(main())
