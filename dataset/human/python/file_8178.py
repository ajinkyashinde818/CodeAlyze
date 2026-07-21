INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
def do():
    k,s=INTM()
    ct=0
    for x in range(k+1):
        for y in range(k+1):
            z=s-x-y
            if 0<=z and z<=k:
                ct+=1
    print(ct)
if __name__ == '__main__':
    do()
