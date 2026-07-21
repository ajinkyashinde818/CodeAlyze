def main():
    n,k,s = map(int,input().split())
    if k == n:
        arr = [s]*n
    elif k == 0:
        if s == 10**9:
            s = 1
        else:
            s += 1

        arr = [s]*n
    else:
        arr = []
        if s == 1:
            for i in range(k):
                arr.append(s)
        else:
            arr.append(1)
            arr.append(s-1)
            k -= 1
            if k%2 == 0:
                while k > 0:
                    arr.append(1)
                    arr.append(s-1)
                    k -= 2
            else:
                while k > 1:
                    arr.append(1)
                    arr.append(s-1)
                    k -= 2

                arr.append(1)
                    
        if s == 10**9:
            s = 2
        else:
            s = 10**9
            
        while len(arr) != n:
            arr.append(s)

    for i in arr:
        print(i,end = ' ')


main()
