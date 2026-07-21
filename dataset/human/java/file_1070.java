import java.lang.Math.sqrt

data class Point(val x:Double, val y:Double){
    operator fun minus(that:Point):Vector = Vector(x - that.x, y - that.y)
    fun distantFrom(that:Point):Double = (this - that).let{(x, y) -> sqrt(x * x + y * y)}
    fun vectorTo(that:Point):Vector = (that - this).let{(x, y) -> Vector(x, y)}
}
data class Vector(val x:Double, val y:Double){
    fun length():Double = sqrt(x * x + y * y)
}
class Angle private constructor(val sin:Double, val cos:Double){
    fun isObtuse():Boolean = cos < 0
    fun isNarrowThan(that:Angle):Boolean = cos > that.cos
    companion object {
        fun angleFromCos(cos:Double):Angle = Angle(sqrt(1 - cos * cos), cos)
        fun angleFromSin(sin:Double):Angle = Angle(sin, sqrt(1 - sin * sin))
        fun angleBetweenVector(a:Vector, b:Vector):Angle = angleFromCos((a.x * b.x + a.y * b.y) / a.length() / b.length())
    }
}
data class Circle(val center:Point, val radius:Double)
class Seeker(val position:Point)
class Target(val position:Point)

fun isCoveredByCircle(seeker:Seeker, target: Target, circle: Circle):Boolean {
    return when{
        seeker.position.distantFrom(circle.center) < circle.radius &&
                target.position.distantFrom(circle.center) < circle.radius -> false
        seeker.position.distantFrom(circle.center) < circle.radius &&
                target.position.distantFrom(circle.center) > circle.radius -> true
        seeker.position.distantFrom(circle.center) > circle.radius &&
                target.position.distantFrom(circle.center) < circle.radius -> true
        else -> {
            val circleViewAngle = Angle.angleFromSin(circle.radius / seeker.position.distantFrom(circle.center))
            val targetViewAngle = Angle.angleBetweenVector(seeker.position.vectorTo(target.position), seeker.position.vectorTo(circle.center))
            when{
                circleViewAngle.isNarrowThan(targetViewAngle) -> false
                else ->{
                    val targetSeekerAngleFromCircle = Angle.angleBetweenVector(circle.center.vectorTo(seeker.position), circle.center.vectorTo(target.position))
                    targetSeekerAngleFromCircle.isObtuse()
                }
            }
        }
    }
}
fun solve(n:Int):Unit{
    if (n == 0) return
    val circles = (0 until n).map{
        val (x, y, r) = readLine()!!.split(' ').map(String::toDouble)
        Circle(Point(x, y), r)
    }
    for (d in 0 until readLine()!!.toInt()){
        val (tx, ty, sx, sy) = readLine()!!.split(' ').map(String::toDouble)
        val target = Target(Point(tx, ty))
        val seeker = Seeker(Point(sx, sy))
        println(when{
            circles.any{isCoveredByCircle(seeker, target, it)} -> "Safe"
            else -> "Danger"
        })
    }
    solve(readLine()!!.toInt())
}
fun main(args:Array<String>):Unit{
    solve(readLine()!!.toInt())
}
