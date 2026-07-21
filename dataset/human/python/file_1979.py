def hult(ans)
  puts ans
  exit
end

def check(x, y)
  zip = @a[y..(y + @m - 1)].map { |s|
    s[x..(x + @m - 1)]
  }.zip(@b)
  hult 'Yes' if zip.all? { |a, b| a == b }
end

@n, @m = gets.split.map(&:to_i)
@a = @n.times.map { gets.chomp }
@b = @m.times.map { gets.chomp }
i = @n - @m + 1
i.times do |w|
  i.times do |h|
    check(w, h)
  end
end
hult 'No'
