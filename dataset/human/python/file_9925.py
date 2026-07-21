object Main extends App {
    def gcd(a: Long, b: Long): Long = {
        if(b == 0) a
        else gcd(b, (a % b))
    } 

    def lcm(a: Long, b: Long): Long = (a * b) / gcd(a, b)

    val input = io.StdIn.readLine.split(' ').map(_.toLong)
    val a = input(0)
    val b = input(1)

    println(lcm(a,b))
}
