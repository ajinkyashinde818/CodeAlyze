def main():

    s = input()
    xcount = 0
    i, j = 0, len(s)-1
    ans = 0
    while i < j:
        if s[i] != s[j]:
            if s[i] == "x":
                i += 1
                ans += 1
            elif s[j] == "x":
                j -= 1
                ans += 1
            else:
                return -1
        else:
            i += 1
            j -= 1
    return ans

if __name__ == '__main__':
    print(main())
