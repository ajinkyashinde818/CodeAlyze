def main():
    end = list(input())
    n = int(input())
    start = []


    for i in range(n):
        query = input().split()
        q = int(query[0])
        if q == 1:
            start,end = end,start
        else:
            f = int(query[1])
            if f == 1:
                start.append(query[-1])
            else:
                end.append(query[-1])
    print(''.join(start[::-1] + end))
    return

if __name__ == "__main__":
    main()
