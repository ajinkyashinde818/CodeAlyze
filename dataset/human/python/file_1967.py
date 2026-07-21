a = []
a = gets.split.map(&:to_i)
b = []
for i in 0..a[0]-1
  b.push(gets.chomp.split(""))
end
c = []
for i in 0..a[1]-1
  c.push(gets.chomp.split(""))
end

def hantei (m, n, p, b, c)
  t = 0
  for i in 0..p-1
    for j in 0..p-1
      if b[i + m][j + n] != c[i][j]
        t =1
      end
    end
  end
  return t
end        
        
u = []
for m in 0..a[0] - a[1] #x軸の移動
  for n in 0..a[0] - a[1] #y軸の移動
    u.push(hantei(m,n,a[1], b, c))
  end
end
if u.min == 0
  puts "Yes"
else
  puts "No"
end
