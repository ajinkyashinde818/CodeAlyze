num=int(input())

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
    return a

line=prime_factorize(num)
value=0
time=1
ans=0


while len(line)>0:
  value1=line[0]
  if value1!=value:
    num=num/value1
    value=value1
    del line[0]
    time=1
    ans+=1
    
    
  else:
    time+=1
    if line.count(value)<time:
      del line[0:line.count(value)]
      continue
      
    value1=value**time
    num=num/value1
    del line[0:time]
    ans+=1

print(ans)
