def main(S):
  while len(S) > 0:
    if S[-1] == "m":
      if S[-5:] == "dream":
        S = S[:-5]
      else:
        print("NO")
        return 0
    elif S[-1] == "e":
      if S[-5:] == "erase":
        S = S[:-5]
      else:
        print("NO")
        return 0
    elif S[-1] == "r":
      if S[-6:] == "eraser":
        S = S[:-6]
      elif S[-7:] == "dreamer":
        S = S[:-7]
      else:
        print("NO")
        return 0
    else:
      print("NO")
      return 0
  else:
    print("YES")
    
main(input())
