import sys
s=input()
s=s[::-1]
l=list(["maerd","remaerd","esare","resare"])
i=0
while i < len(s):
  ok=0
  for j in l:
    if s[i:i+len(j)] == j:
      ok=1
      i += len(j)
      break
  if ok == 0:
    print("NO")
    sys.exit()
print("YES")
