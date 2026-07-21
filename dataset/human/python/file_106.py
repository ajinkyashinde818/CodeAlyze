import sys

s2nn = lambda s: [int(c) for c in s.split(' ')]
ss2nn = lambda ss: [int(s) for s in list(ss)]
ss2nnn = lambda ss: [s2nn(s) for s in list(ss)]
i2s = lambda: sys.stdin.readline().rstrip()
i2n = lambda: int(i2s())
i2nn = lambda: s2nn(i2s())
ii2ss = lambda n: [sys.stdin.readline() for _ in range(n)]
ii2nn = lambda n: ss2nn(ii2ss(n))
ii2nnn = lambda n: ss2nnn(ii2ss(n))



def main():
    R, G, B, N = i2nn()
    #a = []
    cnt = 0
    R, G, B = sorted((R, G, B), reverse=True)
    for r in range(N // R + 1):
        for g in range((N - R * r) // G + 1):
            #print([r, g, 0], N - R * r - G * g)
            if (N - R * r - G * g) % B == 0:
                cnt += 1
                #a.append([r,g,(N - R * r - G * g) // B])
    #print(a)
    print(cnt)
main()
