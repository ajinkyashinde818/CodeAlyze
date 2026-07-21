def calBonus():
    s = 0
    for i in range(n - 1):
        if a[i + 1] == a[i] + 1:
            s += c[a[i] - 1]

    return s


n = int(input())
a = list(map(int, input().split(" ")))
b = list(map(int, input().split(" ")))
c = list(map(int, input().split(" ")))

base = sum(b)
bonus = calBonus()
print(base + bonus)
