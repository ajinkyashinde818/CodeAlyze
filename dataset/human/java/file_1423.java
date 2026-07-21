import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
        int n = sc.nextInt();
     	int m = sc.nextInt();
        int count = 0; 
        String a[] = new String[n];
        for(int i = 0;i < n;i++){
          a[i] = sc.next();
        }
        String b[] = new String[m];
        for(int i = 0;i < m;i++){
          b[i] = sc.next();
        }
      
      
      
        for(int i =0;i <= n - m;i++){
          for(int j = 0;j <= n - m;j++){
            count = 0;
            for(int k = 0;k < m;k++){
              if(b[k].equals(a[i + k].substring(j,j+m))){
				count++;
              }
            }
            if(count == m){
              System.out.println("Yes");
              System.exit(0);
            }
          }
        }
        System.out.println("No");
    }
}
