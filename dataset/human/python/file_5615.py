def solve(s) :
    f = 0
    b = len(s)-1
    ans = 0
    while True :
        if abs(f-b) <= 1 and s[f] == s[b]:
            return ans
        elif s[f] != s[b] :
            if s[f] == 'x' :
                f += 1
                ans += 1
            elif s[b] == 'x' :
                b -= 1
                ans += 1
            else :
                return -1
        else :
            f += 1
            b -= 1

def main() :
    s = input()
    print(solve(s))

main()
