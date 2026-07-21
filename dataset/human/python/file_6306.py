def main():
    N = input()
    len_N = len(N)
    ans = 0
    pre = 0
    for i in range(len_N-1,-1,-1):
        int_N = int(N[i]) + pre
        if int_N <= 4:
            ans += int_N
            pre = 0
        elif int_N >= 6:
            ans += 10 - int_N
            pre = 1
        elif int_N == 5:
            if i == 0:
                ans += int_N
                pre = 0
            else:
                if int(N[i-1]) <= 4:
                    ans += int_N
                    pre = 0
                else:
                    ans += int_N
                    pre = 1
    else:
        ans += pre
    print(ans)



if __name__ == "__main__":
    main()
