def main():
    d,g = map(int, input().split())
    P,C = [], []
    for i in range(d):
        p,c = map(int, input().split())
        P.append(p)
        C.append(c)

    ans = 1000
    for i in range(2**d):
        sum = 0
        tmp = 0
        bin_array = list(format(i, 'b').rjust(d,'0'))
        for j in range(d):
            if bin_array[j] == '1':
                sum += 100*(j+1)*P[j]+C[j]
                tmp += P[j]
        for j in range(d):
            if bin_array[d-j-1] == '0':
                for k in range(P[d-j-1]-1):
                    if sum >= g:
                        break
                    sum += 100*(d-j)
                    tmp += 1
        if sum >= g:
            ans = min(ans,tmp)
    print(ans)


if __name__ == '__main__':
    main()
