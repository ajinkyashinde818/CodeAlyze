def read_image(size)
  size.times.inject([]){|img, x|
    img + [gets.chop]
  }
end

def sub_image(image, x, y, size)
  image[y, size].map{|row|
    row[x, size]
  }
end

N, M = gets.split.map(&:to_i)
imageA = read_image(N)
imageB = read_image(M)

N.times{|y|
  N.times{|x|
    if imageB == sub_image(imageA, x, y, M)
      puts "Yes"
      exit
    end
  }
}

puts "No"
