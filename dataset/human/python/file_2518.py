import itertools

def main():
    D,G=map(int,input().split())
    P=[]
    C=[]
    PC = []
    for i in range(D):
        p,c=map(int,input().split())
        PC.append([100*(i+1),p,c,(100*(i+1)*p+c)/p])
        P.append(p)
        C.append(c)
    res = 100000
    for i in itertools.permutations(range(D)):
        tp = G
        tn = 0
        for j in i:
            if tp <= (j+1)*100*P[j]:
                tn += (tp+(j+1)*100-1) // ((j+1)*100)
                break
            else:
                tp -= (j+1)*100*P[j]
                tn += P[j]
                tp -= C[j]
                if tp <= 0:break
        res = min(res,tn)

    return res

print(main())
