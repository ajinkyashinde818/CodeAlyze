def main(R, G, B, N):
    arr = [R, G, B]
    arr.sort(reverse=True)
    R, G, B = arr

    c = 0
    for r in range(N//R, -1, -1): 
        new1 = N - r*R
        for g in range(new1//G, -1, -1):
            if (new1 - g*G)%B == 0:
                c +=1
    print(c)

R, G, B, N = (int(i) for i in input().split())
main(R, G, B, N)
