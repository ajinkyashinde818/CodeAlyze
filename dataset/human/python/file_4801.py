INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
def do():
    s=STR()
    t=STR()
    s=sorted(s)
    t=sorted(t,reverse=True)
    #print(s,t)
    flg=0
    ct=min(len(s),len(t))
    for i in range(ct):
        if flg==1 or flg==2:
            break
        if s[i]<t[i]:
            flg=1
        elif s[i]>t[i]:
            flg=2
    if flg==0:
        if len(s)>=len(t):
            flg=2
        else:
            flg=1
    if flg==1:
        print('Yes')
    else:
        print('No')
        
    
if __name__ == '__main__':
    do()
