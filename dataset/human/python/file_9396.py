import sys

n, k = map(int, input().split(" "))
a = [-1] + list(map(int, input().split(" ")))

i = 1
head = []
used = {}
roop = []

index = 0
for _ in range(k):
    index += 1
    i = a[i]
    if i in used:
        head = [ k for k, v in sorted(used.items(), key=lambda x:x[1]) if v < used[i]]
        roop = [ k for k, v in sorted(used.items(), key=lambda x:x[1]) if v >= used[i]]
        if len(head) >= k:
            print(head[k-1])
        else:
            x = (k - 1 - len(head)) % len(roop)
            print(roop[x])
            sys.exit()
    else:
        used[i] = index

print([ k for k, v in sorted(used.items(), key=lambda x:x[1])][k-1])
