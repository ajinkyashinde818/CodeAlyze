import sys
t=[1,4,1,4,1,2,1,2]
for i in sys.stdin:
    l=list(map(int,i[:-1].split()))
    q={}
    for i in range(8):
        e=int("".join(map(str,t[i:]+t[:i])))
        s=sum([j if j<i else i for (i,j) in zip(t[i:]+t[:i],l)])
        if s not in q:
            q[s]=[e]
        else:
            q[s].extend([e])
    print(" ".join([i for i in str(sorted(q[max(q.keys())])[0])]))
