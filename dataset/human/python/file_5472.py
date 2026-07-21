object Main{
  def main(args: Array[String]){
    val input=io.Source.stdin.getLines().mkString("\n")
    println(solve(input).trim())
  }

  def solve(input:String):String={
    val Array(x,y)=input.split(" ")
    if(x<y){
      "<"
    }else if(x==y){
      "="
    }else{
      ">"
    }
  }
}
