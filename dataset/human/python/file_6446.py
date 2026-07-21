import sys
N = int(input())

if N % 2 == 1:
    print(0)
    sys.exit()


count = 0
start = 10
start_lis = []
while start <= N:
    start_lis.append(start)
    start = start // 2
    if int(str(start)[-1]) == 5:
        start *= 10
        
tmp10 = 10
while True:
    count += N // tmp10
    tmp10 *= 10
    if tmp10 > N:
        break

for i in range(1, len(start_lis)):
    tmp = start_lis[i]
    while True:
        count += (N + tmp) // (tmp * 2)
        tmp *= 10
        if tmp > N:
            break

print(count)
#print(*start_lis)
