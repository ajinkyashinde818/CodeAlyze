import math
def calculate(arr1,arr2,zeroExist):
    if (len(arr1) % 2 == 0) or (zeroExist == True):
        return sum(arr2) + sum(arr1)
    else:
        return sum(arr2) + sum(arr1) - 2 * (calculateAbsSmallest(arr1,arr2))


def calculateAbsSmallest(arr1,arr2):
    arr1.sort()
    arr2.sort()
    if len(arr2) == 0:
        return arr1[0]
    return min(arr1[0],arr2[0])

N = int(input())

arr1 = []
arr2 = []
zeroExist = False
for s in input().split(" "):
    if int(s) == 0:
        zeroExist = True
    if int(s) < 0:
        arr1.append(abs(int(s)))
    else:
        arr2.append(int(s))

arr1 = list(arr1)
arr2 = list(arr2)

res = calculate(arr1,arr2,zeroExist)
print(res)
