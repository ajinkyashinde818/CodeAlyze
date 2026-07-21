object Main {

  def main(args: Array[String]): Unit = {
    val N = readLine()
    val As = readLine().split(" ").map(_.toInt)
    val Bs = readLine().split(" ").map(_.toInt)
    val Cs = readLine().split(" ").map(_.toInt)
    
    
    val total = Bs.sum + As.sliding(2).filter(t => {
      t(1) - t(0) == 1
    }).map(t => Cs(t(0)-1)).sum
    
    println(total)
  }
  
}
