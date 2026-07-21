import java.util.Scanner

fun main(args: Array<String>){
    val scanner = Scanner(System.`in`)
    val quantity = scanner.nextInt()
    val result = D0427D(
                    valueArray = Array(quantity){ scanner.nextInt() }
                 ).judge()
    println(result)
}

class D0427D(
  val valueArray: Array<Int>
){
    fun judge(): Long{
        val minus = valueArray.filter { it < 0 }
        val abs   = valueArray.map { Math.abs(it).toLong() }
        return if (minus.size % 2 == 0) abs.sum()
               else                     abs.sum() - abs.min()!!*2
    }
}
