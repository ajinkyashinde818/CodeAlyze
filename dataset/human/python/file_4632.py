def byte_minus(byte, num)
  if 97 <= byte && byte <= 122 then   #小文字
    if byte - 97 >= num then
      return byte - num
    else
      byte_minus(90, num - (byte - 96) )
    end
  elsif 65 <= byte && byte <= 90 then   #大文字
    if byte - 65 >= num then
      return byte - num
    else
      byte_minus(122, num - (byte - 64) )
    end
  end
end

while true do
  n = gets.to_i
  break if n == 0
  keys = gets.split.map {|x| x.to_i}
  cipher = gets.chomp
  cipher.each_byte.with_index do |byte, i|
    key_index = i % keys.size
    print byte_minus(byte, keys[key_index]).chr
  end
  puts ''
end
