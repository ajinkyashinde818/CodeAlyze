def resolve():

    d, g = map(int, input().split())

    p = [0] * d
    c = [0] * d
    for i in range(d):
        p[i], c[i] = map(int, input().split())

    ans = 1010

    for i in range(2 ** d):

        sum = 0
        cnt = 0

        for j in range(d):

            if (i >> (d-1-j)) & 1:
                sum += p[j] * (j+1) * 100
                sum += c[j]
                cnt += p[j]

        if sum >= g:
            ans = min(ans, cnt)

        else:

            for j in range(d)[::-1]:

                if not (i >> (d-1-j)) & 1:
                    additional = -(-(g-sum) // ((j+1)*100))

                    if additional >= p[j]:
                        continue

                    cnt += additional
                    sum += additional * (j+1) * 100
                    break

            if sum >= g:
                ans = min(ans, cnt)

    print(ans)
    
resolve()
