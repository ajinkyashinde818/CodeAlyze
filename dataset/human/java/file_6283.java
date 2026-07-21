import java.util.*;
 
public class Main{
 
	public static void main(String[] args){
 
		Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int S = sc.nextInt();
        
        int count = 0;
        for(int i = 0; i <= K; i++){
          for(int j = 0; j <= K; j++){
            if(i+j == S){
              count++;
            }else{
              int s = S-i-j;
                 if(s >= 0 && s <= K){
                     count++;
              }  
            }
          }
        }
      
      
      
       System.out.println(count);
   }
}
