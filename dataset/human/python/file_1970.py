n, m = gets.split.map(&:to_i)
image_a = []
n.times do
  image_a << gets.chomp
end
image_b = []
m.times do
  image_b << gets.chomp
end

def get_indices(line, part)
  offset = 0
  indices = []
  while index = line.index(part, offset)
    indices << index
    offset = index + part.length
  end
  indices
end

find = false
(n-m+1).times do |current_line|
  break if find
  get_indices(image_a[current_line], image_b[0]).each do |current_index|
    flag = true
    m.times do |check_line|
      next if check_line == 0
      unless image_a[current_line+check_line][current_index..current_index+m-1] == image_b[check_line]
        flag = false
        break
      end
    end
    if flag
      find = true
      break
    end
  end
end
puts find ? "Yes" : "No"
