def arcsuf(k,i,j)
  if i > j
    z = i
    i = j
    j = z
  end
  return i*(2*k-i-3)/2 + j
end

n = gets.to_i
x = 8*n+1
y = Math.sqrt(x).to_i
if y*y != x
  print "No"
  exit
end

k = (y+1)/2
print "Yes\n#{k}\n"
for i in 0..(k-1)
  print "#{k-1} "
  for j in 0..(k-1)
    next if j == i
    print "#{arcsuf(k,i,j)} "
  end
  print "\n"
end
