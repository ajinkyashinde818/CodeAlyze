def ma():
    return map(int,input().split())
def main():
    n,k=ma()
    A=list(ma())
    ans=[]
    exp=[0]*(n+1)
    now=1
    
    while True:
        ans.append(now)
        exp[now]=1
        now=A[now-1]
        if exp[now]==1:
            use=ans.index(now)
            tool=len(ans)-use
            break 

    if use>=k:
        print(ans[k])
        exit()
    else:
        p=(k-use)%tool
        print(ans[use+p])

main()
