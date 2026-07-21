object Main{
	def main(args:Array[String]){
		val s = new java.util.Scanner(System.in)
		val a,b,c,n = s.nextInt
		var r = 0
		for(i <- 0 to 3000) {
			for(j <- 0 to 3000) {
				val t = n - i * a - j * b
				if(t >= 0 && t % c == 0) {
					r += 1
				}
			}
		}
		println(r)
	}
}
