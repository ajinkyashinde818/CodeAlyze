import math
import bisect

N = int(input())

def printCount(N):
    if N <= 1:
        print(0)
        return

    num = N
    primeDivisions = []

    limit = [1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325, 351, 378, 406, 435, 465, 496, 528, 561, 595, 630, 666, 703, 741, 780]

    primeCounts = []
    for factor in range(2, int(math.sqrt(N)) + 1):
        if num % factor != 0:
            continue
        count = 0
        while num % factor == 0:
            count += 1
            num //= factor
        primeCounts.append(count)
    if num != 1:
        primeCounts.append(1)

    if len(primeCounts) == 0:
        print(1)
    else:
        result = 0
        for count in primeCounts:
            index = bisect.bisect_right(limit, count)
            result += index
        print(result)

printCount(N)
