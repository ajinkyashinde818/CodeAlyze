'''
def a(b):
    if b <= 1:
        return 1
    return b*a(b-2)
'''
n = int(input())

count = 1

ans = 0
if n%2 == 1:
    print(0)
else:
    for i in range(50):
        kakeru = 10*5**i
        if kakeru <= n:
            ans += n//kakeru
            count *= 10
        else:
            break

    print(ans)
