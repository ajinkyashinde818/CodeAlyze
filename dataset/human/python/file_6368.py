import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    n=int(input())
    if n%2==1:
        print(0)
    elif n<10:
        print(0)
    else:
        ans=0
        for i in range(1,1000000):
            y=5**i
            num=(n//y)//2
            if num==0:
                break
            else:
                ans+=num
        print(ans)
resolve()
