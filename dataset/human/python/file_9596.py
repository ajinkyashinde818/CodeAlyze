N, K = map(int, input().split())
A = [0] + list(map(int, input().split()))
import collections

visi_point = collections.defaultdict(list)

posi = 1
for i in range(K):
    next_posi = A[posi]
    if len(visi_point[next_posi]) >= 2:
        break
    visi_point[next_posi].append(i+1)
    posi = next_posi
# print(visi_point)

for k, v in visi_point.items():
    if K in v:
        print(k)
        break
    if len(v) >= 2:
        if (K - v[0]) % (v[1] - v[0]) == 0:
            print(k)
            break
