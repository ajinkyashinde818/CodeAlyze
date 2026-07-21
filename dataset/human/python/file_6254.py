ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))
inf = 10 **9 + 5
def main():
    s = str(input())
    s = s[::-1]
    dp1 = [inf] *(10 ** 6 +3)
    dp2 = [inf] *(10 ** 6 +3)
    dp1[0] = int(s[0])
    dp2[0] =  10 -int(s[0])
    for i in range(1,len(s)):
        dp1[i] = min(dp2[i-1] + int(s[i]) + 1,dp1[i-1] + int(s[i]))
        dp2[i] = min(dp2[i-1] + 9 - int(s[i]),dp1[i-1] + 10 - int(s[i]))
    print(min(dp1[len(s)-1],dp2[len(s)-1] + 1))

main()
