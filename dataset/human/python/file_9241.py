import sys
S = input().rstrip()
S = S[::-1]
S1 = "dream"
S2 = "dreamer"
S3 = "erase"
S4 = "eraser"
S1 = S1[::-1]
S2 = S2[::-1]
S3 = S3[::-1]
S4 = S4[::-1]
while len(S) > 0:
  if S[0:len(S1)] == S1:
    S = S[len(S1):]
  elif S[0:len(S2)] == S2:
    S = S[len(S2):]
  elif S[0:len(S3)] == S3:
    S = S[len(S3):]
  elif S[0:len(S4)] == S4:
    S = S[len(S4):]
  else:
    print("NO")
    sys.exit()
print("YES")
