N, M = gets.chomp.split.map(&:to_i)
$aa = []
N.times do
  $aa << gets.chomp
end
$bb = []
M.times do
  $bb << gets.chomp
end

ans = "No"

def match(x, y)
  ret = true
  for i in 0..(M - 1) do
    for j in 0..(M - 1) do
      unless $aa[y + j][x + i] == $bb[j][i]
        ret = false
        break
      end
    end
    break if ret == false
  end
  ret
end

for i in 0..(N - M) do
  for j in 0..(N - M) do
    ret = match(j, i)
    if ret
      ans = 'Yes'
      break
    end 
  end
  break if ans == 'Yes'
end

puts ans
