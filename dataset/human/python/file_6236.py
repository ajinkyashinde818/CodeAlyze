import sys

def solve():
    N = str(input())
    dig = len(N)
    ans = 0
    up = False
    for i in reversed(range(dig)):
        n = int(N[i])
        if 0 <= n <= 4: 
            if up: 
                ans += n + 1
                up = False
                if n == 4:
                    if i > 0:
                        if int(N[i-1]) >= 5: up = True
            else: 
                ans += n 
                up = False
        elif n == 5:
            if up: ans += 4
            else: 
                ans += 5
                if i > 0:
                    if int(N[i-1]) >= 5: up = True
        else: 
            if up: ans += 9 - n
            else: ans += 10 - n
            up = True
        #print(n, ans)
    if up: ans += 1
    print(ans)

    return 0

if __name__ == "__main__":
    solve()
