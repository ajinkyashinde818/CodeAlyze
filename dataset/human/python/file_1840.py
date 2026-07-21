n, m = map(int, input().split())
a = []
b = []

for x in range(n):
    a.append(list(input()))

for y in range(m):
    b.append(list(input()))


def check_photo(base, target):
    for i in range(n-m+1):
        check = base[i:i+m]
#        print(check)
        for j in range(n-m+1):
            check2 = [line[j:j+m] for line in check]
#            print(check2)
            if check2 == target:
                return print('Yes')
    return print('No')

check_photo(a, b)
