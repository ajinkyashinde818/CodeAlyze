def main()
  n,m = gets.chomp.split(' ').map(&:to_i)
  table = Array.new(n).map{Array.new}
  for i in 0..m-1
    a,b = gets.chomp.split(' ').map(&:to_i)
    table[a] << b
  end
  flag = false
  table[1].each{|t| flag = true if table[t].include?(n)}
  if flag
    puts "POSSIBLE"
  else
    puts "IMPOSSIBLE"
  end
end

main()
