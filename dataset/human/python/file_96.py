R, G, B, N = map(int, input().split())

def f(a, b):
    sho, amari = int(a/b), a%b
    return sho, amari


def ans(l, m, s):
    cnt = 0

    R_s, R_a = f(N, l)

    for i in range(R_s + 1):
        x = R_a + i * l # R を i 個使う
        G_s, G_a = f(x, m)
        for j in range(G_s + 1):
            y = G_a + j * m # G を j 個使う
            if y % s == 0:
                cnt += 1
    return cnt

li = [R, G, B]
li.sort(reverse=True)

cnt = ans(li[0], li[1], li[2])

print(cnt)
