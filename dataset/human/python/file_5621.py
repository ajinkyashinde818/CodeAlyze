import math
s = str(input())
cou = 0
co = 0
ans = 0
while cou + co +2 <= len(s):
  if s[cou] == "x":
    if s[-1-co] == "x":
      cou += 1
      co += 1
    else:
      cou += 1
      ans += 1
  else:
    if s[-1-co] == "x":
      co += 1
      ans += 1
    else:
      if s[cou] == s[-1-co]:
        cou += 1
        co += 1
      else:
        print(-1)
        exit()
print(ans)
