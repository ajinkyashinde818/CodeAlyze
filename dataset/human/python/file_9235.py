def main():
    S = input()[::-1]
    s1 = "dream"[::-1]
    s2 = "dreamer"[::-1]
    s3 = "erase"[::-1]
    s4 = "eraser"[::-1]
    ans = "NO"
    while True:
        match_flag = False
        for c in [s1, s2, s3, s4]:
            if S[0:len(c)] == c:
                match_flag = True
                S = S.replace(c, "", 1)
                break
        if match_flag is False:
            break
        if S == "":
            ans = "YES"
            break
    print(ans)

if __name__ == '__main__':
    main()
