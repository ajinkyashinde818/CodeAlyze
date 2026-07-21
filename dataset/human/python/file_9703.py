import sys

n, k = map(int, input().split())
a = list(map(int, input().split()))

for i in range(n):
    a[i] = a[i]-1


if k<=n:
    current_posi = 0
    for i in range(k):
        current_posi = a[current_posi]
    print(current_posi+1)
    sys.exit()


posi_roop = [0]
for_search = set([0])

current_posi = 0
for i in range(n):
    current_posi = a[current_posi]
    if current_posi not in for_search:
        posi_roop.append(current_posi)
        for_search.add(current_posi)
    else:
        for j in range(len(posi_roop)):
            if posi_roop[j] == current_posi:
                true_start = j
                break
        true_roop = posi_roop[true_start:]
        consume = true_start
        break
pp = (k-consume) % len(true_roop)

print(true_roop[pp]+1)
