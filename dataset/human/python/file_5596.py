if __name__ == '__main__':
    s = list(input())
    rev_s = list(reversed(s))
    ans = 0
    l, r = 0, len(s) - 1

    while l < r:
        if s[l] == s[r]:
            l += 1
            r -= 1
        elif s[l] == 'x':
            l += 1
            ans += 1
        elif s[r] == 'x':
            r -= 1
            ans += 1
        else:
            print(-1)
            exit(0)
    print(ans)
