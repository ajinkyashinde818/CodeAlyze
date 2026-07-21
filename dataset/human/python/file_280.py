object Main{
	def main(args:Array[String]){
		val s = new java.util.Scanner(System.in)
		val n = s.nextInt
		val a = Array.fill(n)(s.nextLong)
		for(i <- 0 to n - 2) {
			if(a(i) < 0) {
				a(i) *= -1
				a(i + 1) *= -1
			}
		}
		val sum = a.sum
		val f = if(a(n - 1) >= 0) 0
		else a(n - 1) * -2 + a.map(math.abs).min * -2
		println(sum + f)
	}
}
