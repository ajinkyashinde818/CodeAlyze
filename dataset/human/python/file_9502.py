import sys

n, k = map(int, input().split())
A = list(map(int, input().split()))

route = [1]
appearance = set()
index = 1
cnt = 0
flg = False
for _ in range(k):
    if index in appearance:
        flg = True
        break
    appearance.add(index)
    cnt += 1
    next_city = A[index - 1]
    route.append(next_city)
    index = next_city

if flg is False:
    print(route[k])
    sys.exit()

# 繰り返し個数
duplicate = route[route.index(index):len(route) - 1]
print(duplicate[(k - cnt) % (len(duplicate))])
# print(duplicate)
# print(route)
