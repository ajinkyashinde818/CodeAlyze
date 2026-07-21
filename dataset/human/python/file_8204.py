def saiki(sumn,count)
  if (count == 3)
    if ((($s - sumn) <= $k) and (($s - sumn) >= 0))
      $ans += 1
    end
    return
  end
  (0..$k).each do |d|
    sum = sumn + d
    saiki(sum,(count+1))
  end
end
$k,$s = gets.chomp.split(" ").map(&:to_i)
$ans = 0
saiki(0,1)
puts $ans
