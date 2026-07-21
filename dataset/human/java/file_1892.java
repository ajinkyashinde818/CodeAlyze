import java.util.*;
 
class Main {
  public static void main(String[] args) {
	Scanner scanner = new Scanner(System.in);
    
    int D = scanner.nextInt(); //next(文字列), nextDouble, nextLine(1行)とか   
    int G = scanner.nextInt();
    int[] p = new int[D];
    int[] q = new int[D];
    
    for (int i = 0; i < D; i++){
      p[i] = scanner.nextInt();
      q[i] = scanner.nextInt();
    }    
    
    int min = 0;
    int ans = 1000000;
    for (int bit = 0; bit < (1<<D);bit++){
      int temp = 0;
      int tempAns = 0;
      for (int j = 0; j < D; j++){
        if ((bit & (1 << j)) != 0){
          temp += 100*(j+1)*p[j] + q[j];
          tempAns += p[j];
        }
      }
      if (temp >= G){
        if (ans > tempAns){
          ans = tempAns;
        }
      }else{
        for (int j = D-1; j>=0;j--){
        	if ((bit & (1 << j)) == 0){
              for (int k = 0; k < p[j]; k++){
                temp += (j+1)*100;
                tempAns++;

                if(temp >= G){break;}
              }
            }
            if(temp >= G){break;}
        }
        if(ans>tempAns){
          ans = tempAns;
        }
      }
    }
    System.out.println(ans);     
  }
}
