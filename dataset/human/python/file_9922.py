import Foundation

func main(){
   let line = readLine()!.split(separator: " ")

   let a = Int(line[0])!
   let b = Int(line[1])!

   var answer: Int = 0
   var multiplier1 = 1
   let multiplier2 = max(a, b)
   let multiplier3 = min(a, b)
   while answer == 0 {
      if multiplier2 * multiplier1 % multiplier3 == 0 {
         answer = multiplier2 * multiplier1
      }
      multiplier1 += 1
   }

   print(answer)
}
main()
