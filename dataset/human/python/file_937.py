N,C = gets.split.map &:to_i
Sushis = (0...N).map{ gets.split.map &:to_i }

def solve(sushis)
  sv = 0
  cg = 0
  counter_gain = [0] + sushis.reverse_each.map{ |x,v|
    sv += v
    cg = [sv - 2*(C - x), cg].max
  }
  sv = 0
  ans = (0...N).map{ |i|
    x,v = sushis[i]
    sv += v
    sv - x + counter_gain[-i-2]
  }.max
  #p Sushis, counter_gain, ans
  ans
end

p [0, solve(Sushis), solve(Sushis.reverse.map{ |x,v| [C-x,v] })].max
