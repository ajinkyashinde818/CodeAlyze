import sys
sys.setrecursionlimit(10**5)

n = int(input())
a = list(map(int, input().split()))
dp = [[None]*(2) for _ in range(n+1)]

dp[n-1][0] = a[n-1]
dp[n-1][1] = -a[n-1]

for i in reversed(range(n-1)):
    for j in range(2):
        #print('\n# i: ' + str(i))
        # Unexe
        unexe_unexe = a[i] + dp[i+1][0]
        exe_unexe = -a[i] + dp[i+1][1]
        dp[i][0] = max(unexe_unexe, exe_unexe)

        # Exe
        unexe_exe = a[i] + dp[i+1][1]
        exe_exe = -a[i] + dp[i+1][0]
        dp[i][1] = max(unexe_exe, exe_exe)

#print(dp)
#print(max(dp[0][0], dp[0][1]))
print(dp[0][0])
