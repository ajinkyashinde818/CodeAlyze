import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    from collections import defaultdict
    dd = defaultdict(int)
    
    N=I()
    A=LI()
    B=LI()
    
    cntA=[0]*(N+1)
    cntB=[0]*(N+1)
    
    for i in range(N):
        cntA[A[i]]+=1
        cntB[B[i]]+=1
        
    cnt=[0]*(N+1)
    # 合計がNより多いと無理
    for i in range(N+1):
        v1=cntA[i]
        v2=cntB[i]
        if v1+v2>N:
            print("No")
            exit()
        cnt[i]=v1+v2
       
    ans=B[::-1]
    
    same=-1
    for i in range(N):
        if A[i]==ans[i]:
            same=A[i]
            break
    
    sames=[]
    nots=[]
    for i in range(N):
        if A[i]==same and ans[i]==same:
            sames.append(i)
        elif A[i]!=same and ans[i]!=same:
            nots.append(i)
            
    if len(nots)<len(sames):
        print("No")
        exit()
    
    for i in range(len(sames)):
        ans[sames[i]],ans[nots[i]] = ans[nots[i]], ans[sames[i]]
        

 
    print("Yes")
    print(' '.join(map(str, ans)))
                
            


main()
