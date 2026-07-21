k,n = gets.chomp.split(' ').map(&:to_i)
an = gets.chomp.split(' ').map(&:to_i)
ans = 1000000
def dif_forward(ary,num,distance)
    if num == 0
        dif = ary[-1] - ary[num]
    else
        dif = distance - (ary[num] - ary[num-1])
    end
    dif
end

def dif_backward(ary,num,distance)
    if num == (ary.size-1)
        dif = distance - (ary[0] + distance - ary[num])
    else
        dif = distance - (ary[num+1] - ary[num])
    end
    dif
end
an.size.times do |i|
    temp = [dif_forward(an,i,k),dif_backward(an,i,k)].min
    if ans > temp
        ans = temp
    end
end
puts ans
