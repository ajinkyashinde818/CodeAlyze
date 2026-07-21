import sys
input = lambda: sys.stdin.readline().rstrip()
n, k = map(int, input().split())

a = list(map(int, input().split()))

check = [False for _ in range(n + 1)]
route = [1]
check[1] = True
now = a[0]
cnt = 1
while (1):
    # roup += 1
    # route.append(now)
    if cnt == k:
        print(now)
        exit()

    if check[now]:
        break
    else:
        check[now] = True
        route.append(now)
        cnt += 1
        now = a[now - 1]

indexnow = route.index(now)
roop_length = len(route) - indexnow
new_route = route[indexnow:]
# print(indexnow)
# print(new_route)
# print(roop_length)
# print(route)

print(new_route[(k - indexnow) % roop_length])
