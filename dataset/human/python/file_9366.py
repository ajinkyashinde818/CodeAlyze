import copy

n, k = map(int, input().split())
nums = list(map(int, input().split()))

ref = [False] * (n + 1)
cyc = False
cyc_num = -1

idx = 0
path = []

while True:
    if ref[idx + 1] == True:
        cyc_num = idx + 1
        break

    cur = nums[idx]
    ref[idx + 1] = True
    path += [idx + 1]
    idx = cur - 1

prev = len(path)

# print('Cyc', cyc_num)
# print('path 1:', ' '.join(list(map(str, path))))

from_idx = 0
for p in path:
    if p == cyc_num:
        break
    else:
        from_idx += 1

new_path = copy.deepcopy(path[from_idx:])

#print('path 2:', ' '.join(list(map(str, new_path))))

start = len(path) - len(new_path)

if k <= start:
    idx = 0

    for i in range(k):
        cur = nums[idx]
        idx = cur - 1

    print(idx + 1)
else:
    k -= start
    k %= len(new_path)

    print(new_path[k])


"""
5 2
2 3 4 5 3
"""
