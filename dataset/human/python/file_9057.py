s=str(input())
def solve(s):
  while (s!=""):
    if s[-5:] in ["dream","erase"]:
      s=s[:-5]
    elif s[-7:]=="dreamer":
      s=s[:-7]
    elif s[-6:]=="eraser":
      s=s[:-6]
    else:
      return "NO"
  return "YES"
print(solve(s))
