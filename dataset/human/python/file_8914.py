import scala.util.control.Breaks

object Main extends App {
  val sc = new java.util.Scanner(System.in)
  val s = sc.nextLine
  val b = Breaks

  val sRev = s.reverse
  val targets = List("dream".reverse, "dreamer".reverse, "erase".reverse, "eraser".reverse)

  var i = 0
  var flg = true
  b.breakable{
    while(i < sRev.length){
      var isMatch = false
      for(target <- targets) {
        if(i + target.length <= sRev.length && sRev.substring(i, i + target.length) == target){
          isMatch = true
          i += target.length
        }
      }
      if(!isMatch) {
        flg = false
        b.break
      }
    }
  }

  if(flg) {
    println("YES")
  }else{
    println("NO")
  }
}
