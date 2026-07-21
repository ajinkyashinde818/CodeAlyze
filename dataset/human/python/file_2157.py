def cin; gets.split.map(&:to_i) end
def cout(*x); puts x.join(" ") end

exit if $0 != __FILE__

D = 10**9+7
n = gets.to_i
str = gets.chop
hs = {}
str.chars do |c|
  hs[c] = 0 if !hs[c]
  hs[c] += 1
end

r = hs.values.inject(1) {|cnt, x| (cnt * (x+1)) % D}

puts r-1
