def nasu(N):
  ans = 0
  i = 0
  while i < len(N):
    t = N[i]
    if t < 5 or (t == 5 and i == len(N) - 1) or (t == 5 and N[i + 1] <= 4):
      ans += t
      i += 1
    else:
      ans += 1
      ans += 9 - t
      i += 1
      while i < len(N):
        t = N[i]
        if t < 4 or (t == 4 and i == len(N) - 1) or (t == 4 and N[i + 1] <= 4):
          ans += 1
          break
        else:
          ans += 9 - t
          i += 1
      else:
        ans += 1

  return ans


N = list(map(int, list(input())))

print(nasu(N))

exit()
for i in range(500, 600):
  N = list(map(int, list(str(i))))
  print(i, nasu(N))
