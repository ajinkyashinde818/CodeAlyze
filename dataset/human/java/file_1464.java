import java.util.*;
public class Main{
	public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int m = sc.nextInt();
      char[][] s = new char[n][n];
      char[][] t = new char[m][m];
      boolean count = true;
      for(int i = 0;i < n;i++)s[i] = sc.next().toCharArray();
      for(int i = 0;i < m;i++)t[i] = sc.next().toCharArray();
      if(n==1){
      	if(s[0][0]==t[0][0])System.out.println("Yes");
        else System.out.println("No");
      }else{
      for(int i = 0;i < n-m;i++){
      	for(int j = 0;j < n-m;j++){
        	for(int k = 0;k < m;k++){
            	for(int l = 0;l < m;l++){
                	if(s[l+i][j+k]!=t[k][l])count = false;
                }
            }
            if(count){
              System.out.println("Yes");
              return;
            }
            else count = true;
        }
      }
      System.out.println("No");}
    }
}
