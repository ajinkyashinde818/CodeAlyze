def resolve():
    N = int(input())
    eat = list(map(int, input().split()))
    heal = list(map(int, input().split()))
    plus = list(map(int, input().split()))
    ans = 0
    for i in range(N-1):
        if eat[i+1] - eat[i] == 1:
           ans += plus[eat[i]-1]
    print(sum(heal) + ans)
resolve()
