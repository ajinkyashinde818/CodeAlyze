object Main extends App {
	val k = scala.io.StdIn.readLine.split(" ")
	
	def test(x: String): Int = {
		x match {
			case "A" => 10
			case "B" => 11
			case "C" => 12
			case "D" => 13
			case "E" => 14
			case "F" => 15
			case _ => 0
		}
	}

	if(test(k(0)) == test(k(1))){
		println("=")
	}else if(test(k(0)) > test(k(1))){
		println(">")
	}else{
		println("<")
	}

}
