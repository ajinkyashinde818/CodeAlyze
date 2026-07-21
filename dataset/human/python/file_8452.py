def main():

    k, n = map(int,input().split())
    a = list(map(int,input().split()))

    mx = 0
    cnt = 0
    for i in range(1,n):
        tmp = a[i] - a[i - 1]
        if tmp > mx:
            mx = tmp
        cnt += tmp
    tmp = k - a[-1] + a[0]
    if tmp > mx :
        mx = tmp
    cnt = cnt + tmp - mx
    print(cnt)



if __name__ =='__main__':
    main()
