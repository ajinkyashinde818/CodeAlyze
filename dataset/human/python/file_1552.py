n, m = map(int, input().split())

a = [input() for x in range(n)]
b = [input() for x in range(m)]

ball = ''.join(b)

def check():
    for i in range(n):
        if i + m > n:
            continue

        for j in range(n):
            if j + m > n:
                continue

            aall = ""
            for k in range(m):
                aall += a[i+k][j:j+m]

            if aall == ball:
                return True

    return False

ret = "Yes" if check() else "No"
print(ret)
