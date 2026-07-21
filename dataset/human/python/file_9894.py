n,k = gets.split.map(&:to_i)
as = gets.split.map(&:to_i)

TEL = Array.new(n+1,0)

as.each.with_index do |to, from|
  TEL[from+1] = to
end

def detect_cycle(head)
  slow = head
  fast = head

  while true do
    slow = TEL[slow]
    fast = TEL[TEL[fast]]
    break if slow == fast
  end
  
  slow = head
  
  while slow != fast do    
    slow = TEL[slow]
    fast = TEL[fast]
  end
  slow
end

cycle_start = detect_cycle(1)

# count moves before cycle
before_cycle = 0
before_ar = []

if cycle_start != 1
  before_cycle = 1
  current = TEL[1]
  before_ar = [1,current]

  while current != cycle_start do
    current = TEL[current]
    before_cycle += 1
    before_ar.push current
  end
end

if k <= before_cycle
  puts before_ar[k]
  exit 0
end

# count of cycle
current = TEL[cycle_start]
ar = [cycle_start, current]

while current != cycle_start do
  current = TEL[current]
  ar.push current if current != cycle_start
end


i = (k-before_cycle) % ar.size
puts ar[i]
