def resolve():
    n = int(input())
    x = input()
    dict = {}
    for i in range(len(x)):
        if x[i] in dict:
            dict[x[i]] += 1
        else:
            dict[x[i]] = 1
    dictvalue = list(dict.values())
    ans = 1
    for i in dictvalue:
        ans *= (i+1)
        ans %= 10**9+7
    print(ans-1)
resolve()
