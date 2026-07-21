def calc(n):
    if n == 2:
        return [[1], [1]], 1
    lis, val = calc(n - 1)
    for i, l in enumerate(lis):
        l.append(val + 1 + i)
    lis.append(list(range(val + 1, val + n)))
    return lis, val + n - 1

N = int(input())
base = 1
n = 4
while ((base // 2) < N) and (N != 1):
    base = (n - 1) * (n - 2)
    n += 1
if base == (N * 2) or (N == 1):
    lis,_ = calc(n - 2)
    length = len(lis[0])
    k = len(lis)
    print('Yes')
    print(k)
    [print(length, ' '.join(map(str, l))) for l in lis] 
else:
    print('No')
