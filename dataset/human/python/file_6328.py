object Main {
  def main(args: Array[String]): Unit = {
    var input_num = io.StdIn.readLong()

    if(input_num%2 == 1) println(0)
    else {
      input_num = input_num
      var total_five = 0l
      while(input_num >= 10) {
        total_five += input_num/5l/2
        input_num = input_num/5l
      }
      println(total_five)
    }
  }
}
