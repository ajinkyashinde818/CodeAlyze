N,M = gets.split.map(&:to_i)
$es = {}
M.times{
  a,b = gets.split.map(&:to_i)
  $es[a] ||= {}; $es[b] ||= {}
  $es[a][b] = $es[b][a] = 1
}

def r(a,n = 0)
  if a == N
    puts "POSSIBLE"; exit
  end
  return if n >= 2
  $es[a].keys.each{ |b|
    r(b, n+1)
  }
end

r(1)
puts "IMPOSSIBLE"
