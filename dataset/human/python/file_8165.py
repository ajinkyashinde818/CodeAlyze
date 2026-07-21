def f(K, S):
    num=0
    for a in range(K+1):
      if S-a>=0 and S-a<=2*K:
        if S-a<=K:
          num+=S-a+1
        else:
          num+=(K-((S-a)-K))+1
    return num

  
K,S=(int(x) for x in input().split())
print(f(K,S))
