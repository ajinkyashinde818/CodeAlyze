INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
def do():
    n,m=INTM()
    A=[]
    B=[]
    flg=0
    for i in range(n):
        A.append(STR())
    for i in range(m):
        B.append(STR())
    
    for i in range(n-m+1):
        for j in range(n-m+1):
            if A[i][j:j+m] == B[0]:
                temp=1
                for k in range(1,m):
                    if A[i+k][j:j+m] != B[k]:
                        temp=0
                if temp==1:
                    flg=1
    if flg==1:
        print('Yes')
    else:
        print('No')
    
    
if __name__ == '__main__':
    do()
