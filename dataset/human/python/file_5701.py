s = input()
def calc(s):
  ans = 0
  l = 0
  r = len(s)-1
  for i in range(len(s)):
    if l >= r:
      return ans
    if s[l] == s[r]:
      l += 1
      r -= 1
    elif s[l]=='x' and s[r]!='x':
      l += 1
      ans += 1
    elif s[l]!='x' and s[r]=='x':
      r -= 1
      ans += 1
    else:
      return -1
  return ans

a = calc(s)
print(a)
