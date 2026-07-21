s = list(input())
t = list(input())
 
def f(s, t):
  s.sort()
  t.sort(reverse=True)
  s_sum = 0
  t_sum = 0
  for i in range(len(s)):
    s[i] = ord(s[i])
  
  for i in range(len(t)):
    t[i] = ord(t[i])
  
  for i in range(len(s)):
    if not i + 1 >= len(t):
      s_sum += s[i]
      t_sum += t[i]

      if s_sum < t_sum:
        return 'Yes'
      elif s_sum > t_sum:
        return 'No'
    else:
      break

  if len(s) < len(t):
    return 'Yes'
  else:
    return 'No'

print(f(s, t))
