object Main{
    def main(args: Array[String]){
        val inputString = io.StdIn.readLine()
        if (inputString.contains('a') && inputString.contains('b') && inputString.contains('c')) println("Yes") else println("No")
    }
}
