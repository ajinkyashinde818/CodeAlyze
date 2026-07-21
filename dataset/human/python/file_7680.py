def get_i() #空白区切の入力を数値(整数)の配列で返す
  return gets.chomp.split(" ").map(&:to_i)
end
def get_f() #空白区切の入力を数値(実数)の配列で返す
  return gets.chomp.split(" ").map(&:to_f)
end
def get() #空白区切の入力を文字列の配列で返す
  return gets.chomp.split(" ")
end
def get_nsp() #入力されたものを一文字ずつに区切った文字列の配列で返す
  return gets.chomp.split("")
end
def yn_judge(bool,y="Yes",n="No") #boolに真偽を投げることで、trueならy、falseならnの値を出力する
  return bool ? y : n 
end
def array(size,n=1,init=nil) #nに配列の次元数、sizeに配列の大きさ、initに初期値を投げることでその配列を返す
  if n==1
    return Array.new(size){init}
  else
    return Array.new(n).map{Array.new(size){init}}
  end
end

s=get_nsp
q=gets.to_i
temp=0
q.times do
  que=get
  t=que[0].to_i
  case t
  when 1 then
    temp=(temp+1)%2
  when 2 then
    f=(temp+que[1].to_i)%2
    c=que[2]
    if f==1
      s.unshift(c)
    else
      s.push(c)
    end
  end
end
if temp==1
  s.reverse!
end
puts s.join("")
