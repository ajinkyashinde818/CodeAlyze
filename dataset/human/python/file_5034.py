object Main {

	def main(arg:Array[String]) = {
		val list = scala.io.StdIn.readLine().split(" ").map(_.toInt).toList;
		val n = list(0);
		val m = list(1);
		val st1 = scala.collection.mutable.Set.empty[Int];
  		val st2 = scala.collection.mutable.Set.empty[Int];

		for(i <- (0 until m)) {
			val v = scala.io.StdIn.readLine().split(" ").map(_.toInt).toList; // (a, b)
			if (v(0) == 1) st1.add(v(1));
			if (v(1) == n) st2.add(v(0));
		}

		println(if ((2 to n - 1).exists(i => st1(i) && st2(i))) "POSSIBLE" else "IMPOSSIBLE");
	}

}
