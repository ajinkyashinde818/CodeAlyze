def main():

    D, G = map(int, input().split())
    A = []
    for i in range(D):
        p, c = map(int, input().split())
        A.append([i, p, c])
    A = A[::-1]

    hs = [[0, 0, 0]]
    for i, p, c in A:
        temp = []
        for h, v, q in hs: temp.append([h|(1 << i), v+100*(i+1)*p+c, q+p])
        hs += temp

    # print(hs)

    ans = float('inf')
    for h, v, q in hs:
        if v >= G:
            ans = min(ans, q)
        else:
            for i, p, c in A:
                if (h >> i) % 2 == 0:
                    if v + 100*(i+1)*(p-1) < G:
                        v += 100*(i+1)*(p-1)
                        q += p-1
                    else:
                        if (G-v) % (100*(i+1)) == 0:
                            ans = min(ans, q + (G-v) // (100*(i+1)))
                        else:
                            ans = min(ans, q + 1 + (G-v) // (100*(i+1)))
                        break
    return ans

if __name__ == '__main__':
    print(main())
