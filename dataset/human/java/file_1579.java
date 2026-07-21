import java.util.*;

public class Main{

	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        char[][] nn = new char[n][n];
        char[][] mm = new char[m][m];
       
        for(int i = 0; i < n; i++){
          String next = sc.next();
          char[] Next = next.toCharArray();
          for(int j = 0; j < n; j++){
            nn[i][j] = Next[j];
          }
        }
      
        for(int i = 0; i < m; i++){
          String next = sc.next();
          char[] Next = next.toCharArray();
          for(int j = 0; j < m; j++){
            mm[i][j] = Next[j];
          }
        }

      
       boolean ex = false; 
       
       for(int i = 0; i < n-m+1; ++i){
         for(int j = 0; j < n-m+1; ++j){
             boolean match  = false;
             int tcount = 0;
             for(int l = 0; l < m; ++l){
               for(int k = 0; k < m; ++k){
                 if(nn[i+l][j+k] == mm[l][k]){
                   match = true;
                   tcount++;
                 }
               }
               if(match == true && tcount ==m*m){
                 ex = true;
              }
               
             
           }
           
         }
       }
      
       if(ex == true){
         System.out.println("Yes");
       }else{
          System.out.println("No");
       }

	}
}
