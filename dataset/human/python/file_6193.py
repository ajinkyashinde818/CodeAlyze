def check(book, width, m):
    d = 1
    sumv = 0
    for i in range(len(book)):
        if (book[i] > width):
            return False
        if (sumv + book[i] <= width):
            sumv += book[i]
        else:
            sumv = book[i]
            d += 1
    if (d > m):
        return False
    else:
        return True

            
        


if __name__ == "__main__":
    while True:
        m,n = map(int, raw_input().split())
        if (m == 0 and n == 0):
            break
        book = [0 for i in range(n)]
        for i in range(n):
            book[i] = input()
        left,right = 0,1500000
        while (right - left > 1):
            med = (right + left) / 2
            if (check(book, med, m) == True):
                right = med
            else:
                left = med
        print right
