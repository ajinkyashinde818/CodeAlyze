S=lambda:input()
I=lambda:int(input())
L=lambda:list(map(int,input().split()))
LS=lambda:list(map(str,input().split()))

def main():
    import sys
    input = sys.stdin.readline
    n,k=L()
    a=L()
    visited=[0]*(n+1)
    tmp=0
    now=0
    visited[0]=1
    loopat=-1
    for i in range(k):
        #print(visited,end="")
        tmp=i+2
        now=a[now]-1
        #print(now)
        #print(tmp,now+1)
        if visited[now]==0:
            visited[now]=i+2
        else:
            loopat=now
            break
    #print(visited)
    #print(loopat,visited[loopat],tmp)
    #print(tmp,now)
    if loopat==-1:
        print(now+1)
        exit()
    elif tmp-visited[loopat]==0:
        tmp2=k
        dist=1
        now=0
    else:
        tmp2=(k-(visited[loopat]-1))%(tmp-visited[loopat])
        dist=loopat+1
    #print(tmp2)
    
    #print(now,dist)
    #print(now+1,end=" ")
    for i in range(tmp2):
        now=a[now]-1
        dist=now+1
        #print(now,dist)
    #print()
    print(dist)
    
    
if __name__ == '__main__':
    main()
