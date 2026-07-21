INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
def do():
    a=['A','B','C','D','E','F']
    b,c=STRM()
    if a.index(b) < a.index(c):
        print('<')
    elif a.index(b) == a.index(c):
        print('=')
    else:
        print('>')
if __name__ == '__main__':
    do()
