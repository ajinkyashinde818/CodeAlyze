import sys
input = sys.stdin.readline
s = list(input())[: -1]
i = 0
j = len(s) - 1
res = 0
while i < j:
  if s[i] != s[j]:
    res += 1
    if s[i] == "x":
      i += 1
    elif s[j] == "x":
      j -= 1
    else:
      print(-1)
      exit(0)
  else:
    i += 1
    j -= 1
print(res)
