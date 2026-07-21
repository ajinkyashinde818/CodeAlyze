N, K, S = list(map(int, input().split()))
ans = []


def p(lst):
    t = ""
    for i in range(len(lst)-1):
        t += str(lst[i])
        t += " "
    t += str(lst[-1])
    print(t)


if S == 10**9:
    p([S if x < K else 1 for x in range(N)])
else:
    p([S if x < K else S+1 for x in range(N)])
