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
    return Array.new(n){init}
  else
    return Array.new(n).map{Array.new(size){init}}
  end
end

n,m=get_i
a=array(n,n)
b=array(m,m)
n.times do|i|
  a[i]=get_nsp
end
m.times do|i|
  b[i]=get_nsp
end

def incl?(a,b,x,y,n,m)
  m.times do|i|
    m.times do|j|
      next_x=x+j
      next_y=y+i
      return false unless (i<m and j<m and next_x<n and next_y<n and a[next_y][next_x]==b[i][j])
    end
  end
  return true
end
flag=false
n.times do|i|
  n.times do|j|
    if a[i][j]==b[0][0]
      flag=incl?(a,b,j,i,n,m)
      if flag
        break
      end
    end
  end
  break if flag
end
puts yn_judge(flag)
