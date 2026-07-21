import sys
n = int(input())

if(n == 1):
    print('0')
    sys.exit()

maxi = int(n**0.5)
sets = []
for i in range(2,maxi+1):
    aset = 0
    while(n%i == 0):
        aset += 1
        n /= i
    if(aset != 0):
        sets.append(aset)

count = 0
if(n > maxi):
    count += 1
for i in sets:
    start = 1
    while(i >= start):
        i -= start
        count += 1
        start += 1

print(count)
