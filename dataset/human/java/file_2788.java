import java.util.*;

public class Main{

	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);
        String S  = sc.next();
        String T  = sc.next();
        char[] s = S.toCharArray();
        char[] t = T.toCharArray();
        
      
        if(S.equals(T)){
          System.out.println("No");
          return;
        }else if(T.contains(S) && S.length() < T.length()){
          System.out.println("Yes");
          return;
        }
      
        for(int i = 0; i < s.length; i++){
          for(int j = 0; j < t.length; j++){
            if(s[i] < t[j]){
              System.out.println("Yes");
              return;
            }
          }
        }
      
       
        System.out.println("No");
	}
}
