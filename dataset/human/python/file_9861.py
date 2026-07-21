def main():
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    cnt=0
    b=[1]
    res=[-1]*n
    res[0]=0
    flg=0
    now=1
    start=0
    t=1
    while flg==0:
        cnt+=1
        if res[a[now-1]-1]==-1:
            res[a[now-1]-1]=cnt
            b.append(a[now-1])
            now=a[now-1]
        else:
            start=res[a[now-1]-1]
            t=cnt-start
            if cnt<=k:
                flg=1
                k-=start
            else:
                flg=2
    if flg==1:
        print(b[start+(k%t)])
    else:
        print(b[k])
if __name__=="__main__":
    main()
