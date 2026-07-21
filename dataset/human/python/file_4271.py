from collections import deque
N = int(input())

def prime_factorize(n):
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
    a.sort()
    return a

q = deque()
prime = prime_factorize(N)
for x in prime:
  q.append(x)

#print(q)
count = 0
done = []
while N != 1:
  break_flag = False
  if len(q) == 0:
    break
  x = q.popleft()
  #print(N, q, x)
  if x == 1:
    continue
  
  if x in done:
    mul = x
    while mul in done:
      if len(q) == 0:
        break_flag = True
        break
      pop = q.popleft()
      #print(x, pop)
      if x != pop:
        #print(x, pop, q)
        q.appendleft(pop)
        #print(q)
        break_flag = True
        break
      mul *= pop
    x = mul
    if break_flag:
      continue
  
  if N % x == 0:
    N = N // x
    count += 1
    done.append(x)

print(count)
#print(done)
