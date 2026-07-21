INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
def do():
    n=STR()
    if n[0]=='9' or n[1] == '9':
        print('Yes')
    else:
        print('No')
if __name__ == '__main__':
    do()
