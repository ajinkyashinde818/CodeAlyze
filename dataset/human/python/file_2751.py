$d, $g = gets.split.map(&:to_i)
$pc = []
$d.times do
  $pc.push gets.split.map(&:to_i)
end

Inf = 10**9

$dfsh = Hash.new

def dfs(sum, sp)
  return 0 if sum >= $g
  return $dfsh[[sum, sp]] if $dfsh[[sum, sp]]

  min_c = Inf
  0.upto($d - 1) do |i|
    nsp = sp.dup
    sum_i = sum
    next if sp[i] == $pc[i].first

    remain = $g - sum
    take = [remain / ((i + 1) * 100), $pc[i].first].min
    take = 1 if take.zero?
    if take == $pc[i].first
      sum_i += (i + 1) * 100 * take + $pc[i].last
      if sum_i >= $g
        s = take
      else
        nsp[i] = take
        s = take + dfs(sum_i, nsp)
      end
    else
      s = take
    end
    min_c = s if s < min_c
  end
  $dfsh[[sum,sp]] = min_c
end

sp = Array.new($d) { 0 }

puts dfs(0, sp)
