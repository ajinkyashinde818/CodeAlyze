row = STDIN.gets
row = row.to_i

def check (x)
cond = false
 if(x == "m" || x == "c" || x == "x" || x == "i")
  cond = true
 end
  return (cond)
end


def to_int(x)
 num = nil
 case x
 when 'm'
  num = 1000
 when 'c'
  num = 100
 when 'x'
  num = 10
 when 'i'
  num = 1
 end
 return (num)
end

def transfer(x)
 sum = 0
 i = 0

 while(true)
  sub_num = 1 # '○'m
  if(check(x[i]))
   sum = sum + sub_num * to_int(x[i])
  else#数字２〜９が入っていたとき
   sub_num = x[i].to_i
   i = i + 1
   sum = sum + sub_num * to_int(x[i])
  end
  i = i + 1
  if(x[i] == nil)
   break
  end
 end
 return (sum)
end


def transfer_inv(x)
 str = ""
 while(true)
  if(x >= 1000)
   str = str + (x / 1000).to_s + "m"
   x = x - (x/1000) * 1000
  else
   if (x >= 100)
    str = str + (x / 100).to_s + "c"
    x = x - (x/100) * 100
   else
    if (x >= 10)
     str = str + (x / 10).to_s + "x"
     x = x - (x/10) * 10
    else
     str = str + x.to_s + "i"
     x = 0
    end
   end
  end
  if(x == 0)
   break
  end
 end
 return (str.delete("1"))
end






for i in 0...row # !> assigned but unused variable - i
 str = STDIN.gets
 str_array = str.split(" ")
 puts transfer_inv(transfer(str_array[0]) + transfer(str_array[1]))
end
