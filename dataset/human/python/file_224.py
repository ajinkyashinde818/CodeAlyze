import itertools
import sys
N, = [int(i) for i in input().split(' ')]

yn = "No"

if N in []:
    pass
else:
    for i in range(pow(10, 4)):
        c = i * (i-1) // 2
        if c > N:
            break
        elif c == N:
            yn = "Yes"
            k = i
            break

if yn == "No":
    print(yn)
else:
    print(yn)
    print(k)
    co = 1
    d = [[] for i in range(k)]
    for x in itertools.combinations(range(k), 2):
        d[x[0]].append(str(co))
        d[x[1]].append(str(co))
        co += 1
    #print(d)
    for i in range(k):
        print(N*2//k, " ".join(d[i]))
