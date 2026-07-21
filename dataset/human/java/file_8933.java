import java.util.*;

public class Main{
  
  public static void main (String[] args){
    
    Main main = new Main();
    main.solve();
  }
  
  private void solve(){
    
	Scanner scanner = new Scanner (System.in);
    
    int A = scanner.nextInt();
    int B = scanner.nextInt();
    int K = scanner.nextInt();
    
    int count = 0;
    
    int number;
    
    if (A<B){
      number=A;
    }else {
      number=B;
    }
    
    for (; number<=A&&number<=B; number--){
      
      if(A%number==0&&B%number==0){
        count++;
        if (count==K){
          System.out.println(number);
          break;
        }
      }
    }
  }
}
