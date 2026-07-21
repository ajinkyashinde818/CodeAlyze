def make_max(xs)
  rs = []
  ac = xs[0]
  xs.each do |x|
    ac = [ac, x].max
    rs << ac
  end
  rs
end

n, c = gets.split.map(&:to_i)
xs = []
vs = []
vsum = 0
n.times {
  x, v = gets.split.map(&:to_i)
  xs << x
  vs << v
  vsum += v
}

cw = []
ccw = []

ac = 0
cur = 0
n.times do |i|
  x = xs[i]
  v = vs[i]
  ac += v - (x - cur)
  cur = x
  cw << ac
end

ac = 0
cur = 0
n.times do |i|
  x = c - xs[n - 1 - i]
  v = vs[n - 1 - i]
  ac += v - (x - cur)
  cur = x
  ccw << ac
end

cw_max = make_max(cw)
ccw_max = make_max(ccw)

ans = [0, cw.max, ccw.max].max

(n - 1).times do |i|
  ans = [ans, cw[i] - xs[i] + ccw_max[n-i-2]].max
  ans = [ans, ccw[i] - (c - xs[n-1-i]) + cw_max[n-i-2]].max
end

p ans
