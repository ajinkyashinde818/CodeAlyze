def cycle_cnt(start, graph)
  current = graph[start]
  cnt = 1
  while start != current
    current = graph[current]
    cnt += 1
  end

  cnt
end

require "set"

N, K = gets.split.map(&:to_i)
A = gets.split.map(&:to_i)
A.unshift(nil)

traversed = Set.new
traversed.add(1)

current = 1
cnt = 0
detect_flg = true
while cnt != K
  cnt += 1
  current = A[current]
  if traversed.member?(current) && detect_flg
    cycle_cnt = cycle_cnt(current, A)
    cnt += cycle_cnt * ((K - cnt) / cycle_cnt).floor
    detect_flg = false
  end

  traversed.add(current)
end

puts current
