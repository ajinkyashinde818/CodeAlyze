def main():
    from collections import deque
    import sys
    def input():
        return sys.stdin.readline()[:-1]
    S=input()
    Q=int(input())
    A=[input().split() for _ in range(Q)]
    d=deque(S)
    
    d_left=d.appendleft
    d_right=d.append
    j=["1","2"]
    k=0
    j_re=j.reverse
    for x in A:
        if x[0]=="1":
            j_re()
            k+=1
        else:
            if x[1]==j[0]:
                d_left(x[2])
            else:
                d_right(x[2])
    if k%2==1:
        d.reverse()
    print("".join(d))    

if __name__ == '__main__':
    main()
