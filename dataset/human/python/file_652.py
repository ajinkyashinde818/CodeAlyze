require "bigdecimal"
require "bigdecimal/util"

def gi() gets.to_i end
def gs() gets.chomp end
def gmi() gets.split.map(&:to_i) end
def gms() gets.split.map(&:chomp) end
def YesNo1(bool, yes="Yes", no="No") puts (bool ? yes : no) end
def YESNO2(bool, yes="YES", no="NO") puts (bool ? yes : no) end


#####
n = gi
nums = gmi
negCount = 0
zeroCount = 0
nums.each do |num|
  if num < 0
    negCount += 1
  elsif num == 0
    zeroCount += 1
  end
end
res = 0
nums.map!(&:abs).sort!.reverse!
#print nums
res += nums[0..(n-1-negCount%2)].inject(:+)
res -= nums[(n-negCount%2)..-1].inject(:+) if negCount%2 != 0
puts res
