from sys import exit

ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))


def main():
    n = ii()
    ans = 0
    if n%2:
        print(0)
    else:
        tmp = n//2
        while tmp > 0:
            ans+=tmp//5
            tmp//=5

        
        print(ans)

    
main()
