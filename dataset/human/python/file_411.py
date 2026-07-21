import bisect
total = 0
N = int(input())
A = list(map(int, input().split()))
hu = [i for i in A if i < 0]
sei = [i for i in A if i >= 0]
hu.sort()
sei.sort()
if len(hu) % 2 == 0:
    print(sum(sei)+sum(hu)*-1)
else:
    if sei:
        print(sum(sei)+sum(hu)*-1 - min(-1*hu[-1], sei[0])*2)
    else:
        print(sum(sei)+sum(hu)*-1 + 1*hu[-1]*2)
