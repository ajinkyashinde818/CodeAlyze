def main():
    n = int(input())
    a = [int(i) for i in input().split()]

    aabs = [abs(aa) for aa in a]
    tmp = 0
    minabs = min(aabs)
    for aa in a:
        if aa < 0:
            tmp += 1
    if tmp%2==1:
        print(sum(aabs) - 2* minabs)
    else:
        print(sum(aabs))
    # 3 5 7

if __name__ == '__main__':
    main()
