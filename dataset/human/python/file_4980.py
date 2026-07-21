M=10**9+7
def extended_gcd(a, b)
  last_remainder, remainder = a.abs, b.abs
  x, last_x, y, last_y = 0, 1, 1, 0
  while remainder != 0
    last_remainder, (quotient, remainder) = remainder, last_remainder.divmod(remainder)
    x, last_x = last_x - quotient*x, x
    y, last_y = last_y - quotient*y, y
  end
 
  return last_remainder, last_x * (a < 0 ? -1 : 1)
end
def invmod(e)
  g, x = extended_gcd(e,M)
  x % M
end

n,*xs=$<.read.split.map(&:to_i)
np=n-1
npf=(2..np).reduce(1){|s,e| s*e%M }
npfh=npf*invmod(2)%M

s=(xs[np]*(2..np).reduce(npf){|s,e| s+npf*invmod(e) }-xs[np-1]*npf)%M
ts=t=npfh
2.step(np){|i|
  s=(s-xs[i-2]*npf+xs[i-1]*ts)%M
  ts+=t=t*(i-1)*invmod(i+1)%M
}
puts s
