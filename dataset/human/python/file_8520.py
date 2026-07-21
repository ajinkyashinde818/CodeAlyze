def main():
    k, n = [int(i) for i in input().split()]
    pos = [int(i) for i in input().split()]
    res = k - pos[-1] + pos[0]
    for i, j in zip(pos[:-1], pos[1:]):
        if res < j -i:
            res = j-i
    print(k - res)


if __name__ == '__main__':
    main()
