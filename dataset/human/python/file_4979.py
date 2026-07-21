def modinverse(a,m)
  b=m
  u=1
  v=0
  while b>0
    t=a/b
    a-=t*b
    u-=t*v
    a,b=b,a
    u,v=v,u
  end
  u%=m
  if u<0
    u+=m
  end
  return u
end
f=[1]
r=[0]
v=[0]
mod=1000000007
100005.times do |i|
  f << f[-1]*(i+1)%mod
  r << (r[-1]*(i+1)+f[-2])%mod
  v << modinverse(f[-1],mod)
end
n=gets.to_i
x=gets.split.map(&:to_i)
y=[]
(n-1).times do |i|
  y << x[i+1]-x[i]
end
c=0
(n-1).times do |i|
  c+=y[i]*r[i+1]%mod*v[i+1]%mod
  c%=mod
end
puts c*f[n-1]%mod
