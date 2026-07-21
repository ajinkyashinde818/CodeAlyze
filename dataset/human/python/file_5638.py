def palindrome(s):
  for i in range(len(s) // 2):
    if s[i] != s[-i -1]:
      return False
  return True

def main():
  s = input()
  t = ''
  for ch in s:
    if ch != 'x':
      t += ch

  if len(t) == 0:
    print(0)
    return

  if (palindrome(t) == False):
    print(-1)
    return

  cnt = 0
  odd = len(t) & 1
  mid = len(t) // 2

  if odd == 1:  # ax[b]a

    for i in range(len(s)):
      if s[i] != 'x':
        cnt += 1
        if cnt == mid + 1:
          s1 = s[      : i]
          s2 = s[i + 1 :  ]
          break    

  else: # a[x]a

    for i in range(len(s)):
      if s[i] != 'x':
        cnt += 1
        if cnt == mid:
          s1 = s[  : i + 1]
        if cnt == mid + 1:
          s2 = s[i :  ]
          break

  # print(s1, s2)
  ans = 0
  i = 0
  j = 0
  while (i < len(s1) and j < len(s2)):
    c1 = s1[i]
    c2 = s2[-j-1]
    if c1 == c2:
      i += 1
      j += 1
      continue

    ans += 1
    if c1 == 'x':
      i += 1
    else:
      j += 1

  ans += (len(s1) - i) + (len(s2) - j)
  print(ans)






if __name__ == '__main__':
  main()
