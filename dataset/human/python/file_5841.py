from sys import argv

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
c = c + [0] * (len(b) - len(c))
ans = 0
debug = "a" in argv
for index, x in enumerate(a):
    ans += b[x - 1]
    if a[index - 1] + 1 == a[index] and index != 0:
        if debug:
            print(x, index, a[index - 1], a[index])
            print(c[x - 2], c[x - 1])
        ans += c[x - 2]
print(ans)
