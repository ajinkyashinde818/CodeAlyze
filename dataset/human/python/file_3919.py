import collections
def calc_prime(N):
  dic={}
  i=2
  while N != 1:
    d,m=divmod(N,i)
    if m==0:
      N=d
      if i not in dic:dic[i]=1
      else:dic[i]+=1
    else:
      i+=1
  return dic
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
def main():
  N=int(input())
  #dic=calc_prime(N)
  dic=collections.Counter(prime_factorize(N))
  ans=0
  for k,v in dic.items():
    i=0
    while v > i:
      i+=1
      v-=i
    ans+=i
  print(ans)
if __name__ == '__main__':
  main()
