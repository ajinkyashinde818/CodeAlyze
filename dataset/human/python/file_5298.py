S = input().split(" ")
N = int(S[0])
M = int(S[1])
ARR = []

for i in range(M):
    ARR.append([int(s) for s in input().split(" ")])


def calculate(n,m,arr):
    tmp = []
    tmp2 = {}

    for ar in arr:
        f = ar[0]
        t = ar[1]
        if f == 1:
           tmp.append(t)

        tmp2.__setitem__((f,t),True)

    if tmp2.get((1,N)) == True:
        print("POSSIBLE")
        return

    for tm in tmp:
        if tmp2.get((tm,N)) == True:
            print("POSSIBLE")
            return


    print("IMPOSSIBLE")



calculate(N,M,ARR)
