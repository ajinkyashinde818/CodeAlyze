n,m = map(int, input().split())
list_ab = []
for i in range(m):
    list_ab.append(list(map(int, input().split())))
list1 = []
listn = []
for i in range(m):
    if list_ab[i][0] == 1:
        list1.append(list_ab[i][1])
for i in range(m):
    if list_ab[i][1] == n:
        listn.append(list_ab[i][0])

listn.sort()
def binarySearch(list_a, key):
    left = 0
    right = len(list_a)
    while left < right:
        mid = (left + right) // 2
        if list_a[mid] == key:
            return mid
            break
        elif key < list_a[mid]:
            right = mid
        else:
            left = mid+1
    else:
        return "NOT_FOUND"
ans = "IMPOSSIBLE"
for i in range(len(list1)):
    if binarySearch(listn, list1[i]) != "NOT_FOUND":
        ans = "POSSIBLE"
        break

print(ans)
