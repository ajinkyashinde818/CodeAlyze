def main():
    n, k = [int(e) for e in input().split()]
    A = [int(e) for e in input().split()]

    R = [1]
    RS = set(R)
    cnt = 0
    while True:
        nx = A[R[-1] - 1]
        if nx in RS:
            st = R.index(nx)
            R = R[st:]
            break

        R.append(nx)
        RS.add(nx)

        cnt += 1
        if cnt == k:
            print(nx)
            exit()

    m = (k - cnt) % len(R)
    print(R[m - 1])


if __name__ == '__main__':
    main()
