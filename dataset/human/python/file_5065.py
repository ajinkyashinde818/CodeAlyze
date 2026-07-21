def main():
    n,m=map(int,input().split())
    L=[list(map(int,input().split())) for _ in range(m)]
    S=[]
    G=[]
    for l in L:
        if l[0]==1: S.append(l[1])
        if l[1]==n: G.append(l[0])
    print("POSSIBLE"if len(set(S)&set(G))>0 else "IMPOSSIBLE")
main()
