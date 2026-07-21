def solve(s):
    l, r = 0, len(s) - 1

    ans = 0
    while l < r:
        if s[l] != s[r] and s[l] != 'x' and s[r] != 'x':
            return -1
        if s[l] == s[r]:
            l += 1
            r -= 1
        elif s[l] == 'x':
            ans += 1
            l += 1
        elif s[r] == 'x':
            ans += 1
            r -= 1
    return ans


if __name__ == '__main__':
    print(solve(input()))
