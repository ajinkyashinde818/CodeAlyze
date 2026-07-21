require "bigdecimal"
require "bigdecimal/util"

def gi() gets.to_i end
def gs() gets.chomp end
def gim() gets.split.map(&:to_i) end
def gsm() gets.split.map(&:chomp) end
def YesNo1(bool, yes="Yes", no="No") puts (bool ? yes : no) end
def YESNO2(bool, yes="YES", no="NO") puts (bool ? yes : no) end

#####
k,n = gim
nums = gim

gaps = [(nums[0] + k-nums[-1])]
(n-1).times do |i|
  gaps.push(nums[i+1] - nums[i])
end

gaps.sort!
print gaps[0..-2].inject(:+)
