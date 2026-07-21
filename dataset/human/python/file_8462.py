def main():
    k,n = map(int,input().split())
    A = sorted(list(map(int,input().split())))
    mx = 0

    for i,a in enumerate(A):
        if i == 0:
            continue
        if abs(A[i] - A[i-1]) > mx:
            mx = abs(A[i] - A[i-1])

    delta = max(A) - min(A)



    print(min(delta,k-mx))




if __name__ == '__main__':
    main()
