INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
def do():
    n=INT()
    a=LIST()
    b=LIST()
    c=LIST()
    ans=0
    for i in range(n):
        if i==0:
            ans+=b[a[i]-1]
        else:
            ans+=b[a[i]-1]
            if a[i-1]==a[i]-1:
                ans+=c[a[i-1]-1]
    print(ans)
if __name__ == '__main__':
    do()
