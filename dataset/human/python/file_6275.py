if __name__ == "__main__":
    n = '0' + input()

    ans = 0
    flag = 0

    for i in range(len(n)-1, 0, -1):
        if int(n[i]) + flag == 10:
            flag = 1
        elif int(n[i]) + flag > 5 or (int(n[i]) + flag == 5 and int(n[i-1]) > 4):
            ans += 10 - int(n[i]) - flag
            flag = 1
        else:
            ans += int(n[i]) + flag
            flag = 0

    if flag == 1:
        ans += 1

    print(ans)
