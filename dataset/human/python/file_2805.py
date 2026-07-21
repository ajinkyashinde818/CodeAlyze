import kotlin.math.sqrt

//import lib.primeAndIndex

fun primeAndIndex(n : Long): MutableMap<Long, Int> {
    var primeAndIndex: MutableMap<Long, Int> = mutableMapOf()
    var tmp = n
    var i = 2L
    while (tmp != 1L) {
        //println(tmp)
        var indexCount = 0
        while (tmp % i == 0L) {
            tmp /= i
            indexCount++
            //println(tmp)
        }
        //println("end")
        if (indexCount > 0) primeAndIndex[i] = indexCount
        i++
        if (i >= sqrt(n.toDouble())) {
            primeAndIndex[n] = 1
            break
        }
        //println(primeAndIndex)
        //println(tmp)
        //println(i)
    }
    return primeAndIndex
}


fun main(){
    val n = readLine()!!.toLong()
    if(n == 1L){
        println(0)
        return
    }
    val primeAndIndex =  primeAndIndex(n)
    //println(primeAndIndex)
    var count = 0
    primeAndIndex.forEach{
        var sub = 1
        var value = it.value
        while(true){
            //println("$value,$sub")
            if(value >= sub){
                count++
                value -= sub
                sub++
            }else{
                break
            }
        }
    }
    println(count)
}
