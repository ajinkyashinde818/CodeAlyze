D,G=gets.chomp.split(" ").map { |e| e.to_i  }

pl=Array.new(D,0)
c=Array.new(D,0)




D.times do |i|
  pl[i],c[i]=gets.chomp.split(" ").map { |e| e.to_i  }
end

def solve(binary,goal,d,pl,c)
  a=Array.new(D,0)
  leng = binary.length
  binary = binary.reverse
  count = 0

 leng.times do |i|
   if binary[i] == "1"
     count +=  pl[i]
     goal -= 100*(i+1)*pl[i] + c[i]
     a[i] = 1
   end
 end

max = -1

 d.times do |i|
   if a[i] == 0
     max = max > i ? max : i
   end
 end

if goal <= 0
  return count
elsif max == -1
  return 100000000
else
  var = (goal + 100*(max + 1) - 1) / (100*(max + 1))
  if var >= pl[max]
    return 1000000
  else
    return count += var
  end
end

end

ans = 10000000

for i in 0..(2**D-1)
  const = solve(i.to_s(2),G,D,pl,c)
  ans = const > ans ? ans : const
end

puts ans
