import scala.io.StdIn
import scala.collection.mutable._

object Main extends App {

  val Array(n, m) = StdIn.readLine.split(" ").map(_.toInt)
  val graph = Array.fill(n+1)(ListBuffer.empty[Int])
  Iterator.continually(StdIn.readLine)
    .take(m)
    .map(_.split(" ").map(_.toInt))
    .foreach(e => graph(e(0)) += e(1))

  val isPossible = {
    var visited = false
    def dfs(pos:Int, cnt:Int):Unit = {
      if(cnt < 0) return
      if(pos == n) visited = true
      else {
        for(i <- graph(pos)) {
          if(!visited) dfs(i, cnt-1)
          else return
        }
      }
    }
    dfs(1,2)
    visited
  }
  val ans = if(isPossible) "POSSIBLE" else "IMPOSSIBLE"
  println(ans)
}
