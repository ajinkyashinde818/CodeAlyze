INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
def do(): 
    n,r=INTM()
    print(r+(10-min(10,n))*100)
if __name__ == '__main__':
    do()
