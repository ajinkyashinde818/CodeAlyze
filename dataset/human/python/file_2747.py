def inp() a=gets.chomp.split(" ").map(&:to_i)end
def use(d,sum,cost,max)
  if(d > $d)
    $buf.push([sum, cost, max])
    return
  end
  use(d+1,sum+$t[d-1][1]+d*100*$t[d-1][0],cost+$t[d-1][0],max)
  use(d+1,sum,cost,d)
end
$buf = []
$t = []
$d, $g = inp
$d.times{$t<<inp}
use(1,0,0,0)
min = 1e100
$buf.each do |sum,cost,max|
  now = $g - sum
  $t[max-1][0].times do |i|
    break if(now <= 0)
    now -= max*100
    cost += 1
  end
  min = [min,cost].min if(now <= 0)
end
p min
