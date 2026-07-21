N=int(input())

def prime_factorization(n):
    arr=[]
    temp=n

    for i in range(2,int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp//=i
            arr.append([i,cnt])

    if temp!=1:
        arr.append([temp,1])
    
    if arr==[]:
        arr.append([n,1])
    
    return arr
  
def solve():
    if N==1:
        print(0)
        return

    pri_arr=prime_factorization(N)
    ans=0

    for i in range(len(pri_arr)):
        e=pri_arr[i][1]
        temp=0
        cur=1

        while e>=cur:
            e-=cur
            cur+=1
            temp+=1
        
        ans+=temp

    print(ans)
    
if __name__ == "__main__":
     solve()
