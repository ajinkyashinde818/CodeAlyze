def main():
    s = input()

    ss = [i for i in s if i != 'x']
    for i in range(len(ss)//2):
        if ss[i] != ss[len(ss)-1-i]:
            print("-1")
            return

    x_idx, idx, j = [0 for i in range(len(ss)+1)], 0, 0
    while idx < len(s):
        cnt = 0
        while idx < len(s) and s[idx] == 'x':
            cnt += 1
            idx += 1
        x_idx[j] = cnt

        while idx < len(s) and s[idx] != 'x':
            idx += 1
            j += 1

    ans = 0
    for i in range(len(ss)+1):
        if x_idx[i] != x_idx[len(ss)-i]:
            ans += max(x_idx[len(ss)-i], x_idx[i]) - min(x_idx[len(ss)-i], x_idx[i])
            x_idx[i] = x_idx[len(ss)-i] = max(x_idx[len(ss)-i], x_idx[i])

    print(ans)


if __name__ == '__main__':
    main()
