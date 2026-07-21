def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    L=["dream","dreamer","erase","eraser"]
    S=input()
    N=len(S)
    f=1
    pos=N-1
    while f:
        for i in range(len(L)):
            t=L[i]
            temp=1
            for i in range(len(t)):
                if pos-i<0:
                    temp=0
                    break
                if t[-1-i]==S[pos-i]:
                    continue
                else:
                    temp=0
                    break
                
            if temp:
                pos-=len(t)
                break
        if pos==-1:
            break
        if temp==0:
            f=0
            
    if f==1:
        print("YES")
    else:
        print("NO")
                

main()
