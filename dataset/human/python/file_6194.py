def func(q,m,W):
    s = 0
    c = 1
    for w in W:
        s += w
        if s > q:
            c += 1
            s = w
            if s > q:
                return 1
    return (c > m)

while(1):
    m,n=[int(x) for x in input().split()]
    if m==0:
        break
    W=[]
    A=[0]
    for i in range(n):
        W.append(int(input()))
        A.append(A[-1]+W[-1])
    A.pop(0)
    qsmall = sum(W)/m
    qbig   = 1500000
    while(1):
        if qbig - qsmall < 1e-3:
            break
        q = (qbig+qsmall)/2 
        issmall = func(q,m,W)
        if issmall:
            qsmall = q
        else:
            qbig = q
    q = int(qsmall)
    if func(q,m,W):
        print(q + 1)
    else:
        print(q)
