def main():
  s=input()
  t=input()

  sd=list(s)
  sd.sort()
  td=list(t)
  td.sort(reverse=True)

  for (sc,tc) in zip(sd,td):
    if sc<tc:
      print("Yes")
      return
  if len(sd)<len(td) and sd[len(sd)-1]==td[len(sd)-1]:
    print("Yes")
    return
  print("No")

main()
