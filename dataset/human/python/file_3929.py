def prime_decomposition(n):
  i = 2
  table = []
  while i * i <= n:
    while n % i == 0:
      n /= i
      table.append(i)
    i += 1
  if n > 1:
    table.append(n)
  return table

def main():
    N=int(input())
    ans=0
    if N==1:
        print(ans)
        return 
    t=prime_decomposition(N)
    if len(t)==1:
        print(1)
        return 
    dic={}
    for a in t:
        if not a in dic.keys():
            dic[a]=1
            continue
        else:
            dic[a]+=1
    ans=0
    for i in dic.keys():
        num=dic[i]
        tmp=1
        c=1
        while True:
            if num >=c:
                num-=c
                c+=1
                ans+=1
            else:
                break
    print(ans)
main()
