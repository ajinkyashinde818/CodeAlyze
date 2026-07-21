import math

N = int(input())
arr = []
if N == 1:
    print(0)
    quit()


def loop_attr(num):
    temp = num
    for i in range(2, math.ceil(N**0.5)):
        counter = 0
        while(temp%i == 0):
            counter += 1
            temp //= i
        if counter != 0:
            arr.append(counter)
        if temp == 1:
            break

    if temp != 1:
        arr.append(1)


ans = 0
loop_attr(N)
for j in arr:
    count = 1
    while(j - count >= 0):
        j -= count
        count += 1
    ans += (count-1)

print(ans)
