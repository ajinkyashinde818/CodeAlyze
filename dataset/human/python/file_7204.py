INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
def do():
    s=STR()
    q=INT()
    l=''
    r=''
    ct=0
    for i in range(q):
        fc=LISTS()
        if fc[0]=="1":
            ct+=1
        else:
            if fc[1]=="1":
                if ct%2==0:
                    l=fc[2]+l
                else:
                    r=r+fc[2]
            else:
                if ct%2==1:
                    l=fc[2]+l
                else:
                    r=r+fc[2]
    
    sums=l+s+r
    if ct%2==1:
        ans=""
        for i in range(len(sums)-1,-1,-1):
            ans=ans+sums[i]
    else:
        ans=sums
    
    print(ans)
                
if __name__ == '__main__':
    do()
