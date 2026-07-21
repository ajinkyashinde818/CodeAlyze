n = int(input())

def prime_fact(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a  

ps = prime_fact(n)
current = 0
num = 0
tmp_c = 0
cnt = 0
if ps:
  for i in range(len(ps)):
    if ps[i] != current:
      num = 2
      tmp_c = 0
      cnt += 1
      current = ps[i]
    else:
      tmp_c += 1
      if tmp_c == num:
        cnt += 1
        tmp_c = 0
        num += 1
  print(cnt)
else:
  print(0)
