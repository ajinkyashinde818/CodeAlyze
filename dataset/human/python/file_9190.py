S = input()[::-1]
A = ["maerd","remaerd","esare","resare"]
def HIT(ST,A):
  for i in A:
    if ST[:len(i)]==i:
      return ST[len(i):]
    else:
      continue
  return ST
for j in range(len(S)//5+1):
  S = HIT(S,A)
  if S == "":
    break
if S == "":
  print("YES")
else:
  print("NO")
