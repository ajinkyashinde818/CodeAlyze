from collections import deque

def main():
    s = list(input())
    Q = int(input())
    Qry = []
    for i in range(Q):
        q = list(input().split())
        Qry.append(q)
    d = deque(s)

    flg = 0
    l = 0
    r = len(s) -1
    for i, q in enumerate(Qry):
        if int(q[0]) == 1:
            tmp = l
            l = r
            r = tmp
            if flg == 0:
                flg =1
            else:
                flg = 0
        if int(q[0]) == 2:
            if int(q[1]) == 1:
                if flg == 0:
                    d.appendleft(q[2])
                else:
                    d.append(q[2])
            if int(q[1]) == 2:
                if flg ==1:
                    d.appendleft(q[2])
                else:
                    d.append(q[2])
    ans = []
    if flg == 0:
        for _ in range(len(d)):
            ans.append(d.popleft())
    if flg == 1:
        for _ in range(len(d)):
            ans.append(d.pop())
    print(''.join(ans))

if __name__=='__main__':
    main()
