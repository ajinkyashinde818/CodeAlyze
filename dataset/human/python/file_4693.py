MUL = {
  "m" => 1000,
  "c" => 100,
  "x" => 10,
  "i" => 1
}

NUM = (2..9).map &:to_s

def read( v )
  n = 0
  rv = v.split(//).reverse
  i = 0
  while( i < rv.size )
    s = MUL[rv[i]]
    if NUM.include?( rv[i+1] )
      s *= rv[i+1].to_i
      i += 1
    end
    i += 1
    n += s
  end
  return n
end

def put( v )
  s = ""
  MUL.each do |k, m|
    i = v / m
    s += i.to_s if NUM.include?( i.to_s )
    s += k if i != 0
    v = v % m
  end
  return s
end


n = gets.to_i
n.times do
  v1, v2 = gets.chomp.split
  puts put( read( v1 ) + read( v2 ) )
end
