from sys import stdin
import math
    
def calc(r,g,b,n):
    ans = 0

    for ri in range(0, math.floor(n/r)+1):
        numR = ri * r
        if n - numR == 0:
            ans += 1
            continue

        for gi in range(0, math.floor((n-numR)/g)+1):
            numG = gi * g

            left = n - numR - numG
            
            if left == 0:
                ans += 1
            elif left % b == 0:
                ans += 1
    return ans

def main():
    r,b,g,n = [int(x) for x in stdin.readline().rstrip().split()]
    ans = calc(r,b,g,n)
    print(ans)
    
if __name__=='__main__':
    main()
