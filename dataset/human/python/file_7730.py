INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
def do():
    N = INT()
    if N<1200:
        print('ABC')
    else:
        print('ARC')    
if __name__ == '__main__':
    do()
