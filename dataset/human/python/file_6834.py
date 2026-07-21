def main():
    c = 0
    s = input()
    f = ''
    b = ''
    for _ in range(int(input())):
        q = input().split()
        if q[0] == '1':
            c += 1
        else:
            if (q[1] == '1' and c%2 == 0) or (q[1]=='2' and c%2==1):
                f = q[2] + f
            else:
                b += q[2]
    if c % 2 == 0:
        print(f+s+b)
    else:
        print(b[::-1]+s[::-1]+f[::-1])

if __name__ == '__main__':
    main()
