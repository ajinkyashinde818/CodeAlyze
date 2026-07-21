import collections

N, K = map(int, input().split())
city_list = list(map(int, input().split()))
th_list = []
n = 0
for i in range(N):
    th_list.append(n)
    n = city_list[n] - 1

c = collections.Counter(th_list)
for i in range(N):
    if c[th_list[i]] > 1:
        break
list = [x for x, l in enumerate(th_list) if l == th_list[i]]

if K > N:
    print(th_list[(K - list[0]) % (list[1] - list[0]) + list[0]] + 1)
else:
    print(th_list[K] + 1)
