s = gets.chomp

def result(s)
  check_hash = { 'a' => false, 'b' => false, 'c' => false }
  s.each_char do |c|
    return 'No' unless check_hash.has_key?(c)
    return 'No' if check_hash[c]
    check_hash[c] = true
  end
  return 'Yes'
end

puts result(s)
