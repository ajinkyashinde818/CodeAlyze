import sys

sys.setrecursionlimit(10**9)

def dfs(num,lis,count,target):
    visited[num]=count
    n_city=A[num]
    if visited[n_city]!=-1:
        lis.append(num)
        if target<=count:
              print(lis[target]+1)
        else:
            rep=len(lis)-visited[n_city]
            target-=visited[n_city]
            amari=target%rep
            temp=lis[visited[n_city]:]
            print(temp[amari]+1)
        exit()
    else:
        lis.append(num)
        dfs(n_city,lis,count+1,target)
    

N,K=map(int,input().split())
A=list(map(int,input().split()))
A=list(map(lambda x:x-1,A))

visited=[-1]*N

dfs(0,[],0,K)
