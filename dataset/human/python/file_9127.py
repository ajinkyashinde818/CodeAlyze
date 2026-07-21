def check():
  S = input()
  n = len(S)
  dp = [False]*(n+10)
  dp[0] = True
  for i in range(n+1):
    if S[i:i+5]=='dream':
      dp[i+5] |= dp[i]
    if S[i:i+7]=='dreamer':
      dp[i+7] |= dp[i]
    if S[i:i+5]=='erase':
      dp[i+5] |= dp[i]
    if S[i:i+6]=='eraser':
      dp[i+6] |= dp[i]
  if dp[n]==True:
    return 'YES'
  return 'NO'
print(check())
