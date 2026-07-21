object Main extends App {
	val s = scala.io.StdIn.readLine.toList.sorted
	val t = scala.io.StdIn.readLine.toList.sorted.reverse

	def check(a: List[Char], b: List[Char]): Boolean = {
		a match {
			case Nil => b match {
				case Nil => false
				case _   => true 
			}
			case e::rest => b match {
				case Nil => false
				case _ => if(e == b.head) check(rest, b.tail)
							else if( e < b.head) true
							else false
			}
			
		}	
	} 

	if(check(s,t)) println("Yes")
	else println("No")
}
