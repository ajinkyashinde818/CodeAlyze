INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

def do():
    ans=0
    n=INT()
    s=factorization(n)
    for a,b in s:
        temp=0
        for i in range(10):
            temp+=(i+1)
            #print(a,b,temp,ans)
            if temp<=b:
                ans+=1
            else:
                break
    if n==1:
        ans=0
    
    print(ans)

                
if __name__ == '__main__':
    do()
