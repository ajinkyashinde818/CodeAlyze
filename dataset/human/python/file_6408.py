from decimal import *

INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
def do():
    n=INT()
    count=0
    if n%2==1:
        print(0)
    else:
        for i in range(1,30,1):
            b=n//(2*(5**i))
            count+=b
        print(count)
if __name__ == '__main__':
    do()
