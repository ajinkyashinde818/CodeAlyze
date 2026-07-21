def main():
    S = input()

    s1 = S.replace('x', '')
    s2 = s1[::-1]
    if s1 != s2:
        print(-1)
        exit()

    i1 = 0
    i2 = len(S) - 1
    cnt = 0
    while True:
        if S[i1] == 'x' and S[i2] != 'x':
            cnt += 1
            i1 += 1
        elif S[i1] != 'x' and S[i2] == 'x':
            cnt += 1
            i2 -= 1
        else:
            i1 += 1
            i2 -= 1
        if i2 - i1 < 1:
            break

    print(cnt)

main()
