def gs() gets.chomp end
def gi() gets.to_i end
def gsmi() gets.chomp.split.map(&:to_i) end

def desc(ar) ar.sort!{|x,y|y<=>x} end
def min(a,b) a<=b ? a : b end
def max(a,b) a>=b ? a : b end
def sum(ar) ar.inject(:+) end

#$stdin = File.open('input.txt')

d,g = gsmi #10,
pcs = Array.new(d){gsmi} #100, 10**6
points = pcs.map.with_index(1) do |(p,c),i|
  [100*i]*(p-1)+[100*i+c]
end

ans = 1000
(2**d).times do |i| #1000
  js = []
  d.times do |j|
    js << j if (i>>j)&1==1
  end

  js.each do |last|
    sum = 0
    crt = 0
    js.each do |j|
      next if j==last
      break if sum>g
      sum += sum(points[j])
      crt += points[j].length
    end
    #p [sum,js,last,crt]
    next if sum>g
    remain = g-sum
    points[last].each do |points|
      remain -= points
      crt += 1
      break if remain<=0
    end
    #puts "remain: #{remain} crt: #{crt}"
    ans = min(ans,crt) if remain<=0
  end
end

puts ans
