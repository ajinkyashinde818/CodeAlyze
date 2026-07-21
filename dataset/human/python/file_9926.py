object Main extends App {
    val sc = new java.util.Scanner(System.in)

    val a,b = sc.nextLong

    println(lcm(a,b))
    
    def gcd(x:Long,y:Long):Long = if (y > 0) gcd(y,x%y) else x
    def lcm(x:Long,y:Long):Long = x/gcd(x,y) * y
}
