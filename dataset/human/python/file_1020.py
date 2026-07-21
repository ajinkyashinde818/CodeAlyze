import sys
input = sys.stdin.readline
ModNum = 10**9+7

def main():
    N = int(input())
    S = input()

    direction = [0] * (2*N)

    line = 0
    for i in range(2*N):
        if S[i]=="B" and line%2==0:
            direction[i] = 1
            line += 1
        elif S[i]=="B" and line%2==1:
            direction[i] = -1
            line -= 1
        elif S[i]=="W" and line%2==0:
            direction[i] = -1
            line -= 1
            if line < 0:
                print(0)
                break
        elif S[i]=="W" and line%2==1:
            direction[i] = 1
            line += 1
    else:
        if line>0:
            print(0)
        else:
            ans = 1
            Sum = 0           
            for i in range(2*N):  
                if direction[i]==1:
                    Sum += 1
                else:
                    ans *= Sum
                    ans %= ModNum
                    Sum -= 1
            for i in range(1,N+1):
                ans *= i
                ans %= ModNum
            print(ans)




if __name__ == "__main__":
    main()
