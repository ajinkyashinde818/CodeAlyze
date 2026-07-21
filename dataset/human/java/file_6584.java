import java.util.*;

public class Main{
  public static void main(String[] args){
  	Scanner scanner = new Scanner(System.in);
  	int K = scanner.nextInt();
  	int S = scanner.nextInt();
    
    int Z = K;
    int counter = 0;
    while(Z>=0){
      int Y = S-Z;
      if(Y>K){
        Y=K;
      }
      while(Y>=0){
        int X = S-Z-Y;
        if(K>=X && X>=0){
          counter++;
        }
        Y--;
      }
      Z--;
    }
  
  	System.out.println(counter);
  }
}
