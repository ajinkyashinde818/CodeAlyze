s = sorted(input())
t = sorted(input(),reverse=True)
ans = ""
def check_dict():
  for i in range(min(len(s),len(t))):
    if s[i] < t[i]:
      ans = "Yes"
      return ans
    elif s[i] > t[i]:
      ans = "No"
      return ans
  return ""
if len(s) < len(t):
  ans = check_dict()
  if ans == "":
    ans = "Yes"
  print(ans)
else:
  ans = check_dict()
  if ans == "":
    ans = "No"
  print(ans)
