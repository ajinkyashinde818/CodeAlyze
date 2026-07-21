import bisect
n=int(input())
a=sorted(list(map(int,input().split())))
ind=bisect.bisect_left(a,0)


if ind==0 :
  print(sum(a))
  
elif ind==n:
  if ind%2==1:
    print(-sum(a)+2*a[-1])
  else:
    print(abs(sum(a)))

elif ind%2==0:

  print(-sum(a[:ind])+sum(a[ind:]))
else:
  print(-sum(a[:ind])+sum(a[ind:])-2*min(abs(a[ind]),abs(a[ind-1])))
