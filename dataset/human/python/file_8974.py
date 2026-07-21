import sys
S = input()
while len(S)>5:
  if S[-7:] == "dreamer":
    S = S[:-7]
  elif S[-6:] == "eraser":
    S = S[:-6]
  elif S[-5:] == "dream" or S[-5:] == "erase":
    S = S[:-5]
  else:
    print("NO")
    sys.exit()
print("YES")
