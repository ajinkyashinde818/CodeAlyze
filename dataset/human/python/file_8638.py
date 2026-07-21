INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
def do():
    k,n=INTM()
    A=LIST()
    As=[]
    for i in range(n-1):
        As.append(A[i+1]-A[i])
    As.append(k+A[0]-A[n-1])
    print(k-max(As))
    
if __name__ == '__main__':
    do()
