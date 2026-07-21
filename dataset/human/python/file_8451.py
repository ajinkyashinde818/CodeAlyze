import collections

local = False
if local:
    file = open("C.txt", "r")

def inp():
    if local:
        return file.readline().rstrip()
    else:
        return input().rstrip()

K,N = [int(_) for _ in inp().split()]
arr = [int(_) for _ in inp().split()]

temp = 0
max_dist = -1

for a in arr:
    cur_dist = a-temp

    max_dist = max(max_dist, cur_dist)

    temp = a

max_dist = max(max_dist, arr[0] + K-temp)

print(str(K-max_dist))
