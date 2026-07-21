def prnt(c, unit)
  if c != "1" && c != "0"
    print (c + unit)
  elsif c == "1"
    print unit
  end
end

gets.to_i.times do
  count = Hash["m", 0, "c", 0, "x", 0, "i", 0]
  str = gets.chomp.split
  str.each do |s|
    s.gsub(/(?<![1-9])([mcxi])/, '1\1').split("").each_slice(2) do |w|
      count[w[1]] += w[0].to_i
    end
  end
  ans = 0
  count.values.each_with_index{ |n, i| ans += 10 ** (3 - i) * n }
  ans.to_s.rjust(4, "0").split("").each_with_index{ |c, i| prnt(c, count.keys[i]) }
  puts
end
