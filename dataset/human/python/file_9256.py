def main():
    s=input()
    dp=[0]*len(s)
    dp[0]=1
    for i,v in enumerate(s):
        if dp[i] == 0 or i+5 > len(s):
            continue
        s5 = s[i:i+5]
        if s5 == "dream" or s5 == "erase":
            if len(s) == i+5:
                break
            dp[i+5]=1
        if i+6 <= len(s) and s[i:i+6] == "eraser":
            if len(s) == i+6:
                break
            dp[i+6]=1
        if i+5 <= len(s) and s[i:i+7] == "dreamer":
            if len(s) == i+7:
                break
            dp[i+7]=1
    else:
        print("NO")
        return
    print("YES")

if __name__ == "__main__":
    main()
