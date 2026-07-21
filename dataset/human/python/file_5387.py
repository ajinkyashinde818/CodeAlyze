n, m = gets.chomp.split(' ').map(&:to_i)
a = []
b = []
m.times { |i|
  a[i], b[i] = gets.chomp.split(' ').map(&:to_i)
}
def selectFrom(ab, from)
  ab.select { |v|
    v[0] == from
  }.uniq
end
ab = a.zip(b)
from0 = ab.select { |v|
  v[0] == 1
}.map { |v| v[1] }
ton = ab.select { |v|
  v[1] == n
}.map { |v| v[0] }
ret = from0 & ton
puts ret.length != 0 ? 'POSSIBLE' : 'IMPOSSIBLE'
