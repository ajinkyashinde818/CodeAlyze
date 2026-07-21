def solve(n,k,A):
    if A[0]==0:
        return 0
    visited=set()
    visited.add(0)
    C=[0]
    p=A[0]
    while p not in visited:
        visited.add(p)
        C.append(p)
        p=A[p]
    l=len(C)
    s=C.index(p)
    if k<=s:
        return C[k]
    cycle=l-s
    k-=s
    r=k%cycle
    return C[s+r]

def main():
    n,k=map(int,input().split())
    A=tuple(map(lambda x: int(x)-1,input().split()))
    ans=solve(n,k,A)+1
    print(ans)
    
if __name__=='__main__':
    main()
