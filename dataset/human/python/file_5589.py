def main():
    import sys
    input = sys.stdin.readline
    s = input().strip()
    N = len(s)
    l = -1
    r = N
    if len(set(s)) == 1:
        print(0)
        exit()
    while l < r:
        l += 1
        r -= 1
        while s[l] == 'x':
            l += 1
        while s[r] == 'x':
            r -= 1
        if s[l] != s[r]:
            print(-1)
            exit()
    
    ans = 0
    while l != -1 or r != N:
        if l == -1:
            ans += N - r
            break
        if r == N:
            ans += l + 1
            break
        if s[l] == s[r]:
            l -= 1
            r += 1
            continue
        elif s[l] == 'x':
            ans += 1
            l -= 1
        elif s[r] == 'x':
            ans += 1
            r += 1
        
    print(ans)

if __name__ == '__main__':
    main()
