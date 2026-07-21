def solve()
  k, n = gets.split().map!(&:to_i)
  a = gets.split.map!(&:to_i).sort
  x = []
  n.times do |i|
    if i == (n-1)
      x.push(a[0]+k - a[i])
    else
      x.push(a[i+1] - a[i])
    end
  end
  print(x.inject(:+) - x.max)
end
solve()
