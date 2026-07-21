def main():
    n = input()[::-1] + "0"
    s = 0
    cnt = 0
    for i, ni in enumerate(n[:-1]):
        k = int(ni) + s
        if k < 5 or k == 5 and int(n[i + 1]) < 5:
            cnt += k
            s = 0
        else:
            cnt += 10 - k
            s = 1
    cnt += s
    print(cnt)

if __name__ == '__main__':
    main()
