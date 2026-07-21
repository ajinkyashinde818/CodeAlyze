import scala.collection.mutable
import scala.io.StdIn._

object Main extends App {
  val n = readInt
  val nodes = Array.fill(n){Nil: List[(Int, Int)]}
  for (_ ← 1 until n){
    val Array(s, t, w) = readLine.trim.split(' ').map(_.toInt)
    nodes(s) ::= (t, w)
    nodes(t) ::=(s, w)
  }
  val queue = mutable.Queue(0)
  val distanceFromZero = Array.fill(n){-1}
  distanceFromZero(0) = 0
  while (queue.nonEmpty) {
    val current = queue.dequeue()
    for ((next, distance) ← nodes(current) if distanceFromZero(next) == -1) {
      distanceFromZero(next) = distanceFromZero(current) + distance
      queue.enqueue(next)
    }
  }
  val a = distanceFromZero.indices.maxBy(distanceFromZero)
  val distanceFromFurthestA = Array.fill(n){-1}
  distanceFromFurthestA(a) = 0
  queue.enqueue(a)
  while (queue.nonEmpty) {
    val current = queue.dequeue()
    for ((next, distance) ← nodes(current) if distanceFromFurthestA(next) == -1) {
      distanceFromFurthestA(next) = distanceFromFurthestA(current) + distance
      queue.enqueue(next)
    }
  }
  val b = distanceFromFurthestA.indices.maxBy(distanceFromFurthestA)
  val distanceFromFurthestB = Array.fill(n){-1}
  distanceFromFurthestB(b) = 0
  queue.enqueue(b)
  while(queue.nonEmpty) {
    val current = queue.dequeue()
    for ((next, distance) ← nodes(current) if distanceFromFurthestB(next) == -1) {
      distanceFromFurthestB(next) = distanceFromFurthestB(current) + distance
      queue.enqueue(next)
    }
  }
  for (i ← 0 until n){
    println(math.max(distanceFromFurthestA(i), distanceFromFurthestB(i)))
  }
}
