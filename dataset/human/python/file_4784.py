def main():
    s = input()
    t = input()

    sList, tList = list(s), list(t)

    sList.sort()
    tList.sort(reverse=True)

    sortedS = ''.join(sList)
    sortedT = ''.join(tList)

    if sortedS < sortedT:
        print('Yes')
    else:
        print('No')

if __name__ == '__main__':
    main()
