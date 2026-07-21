import java.util.*;
import java.lang.Math;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
        int n = sc.nextInt();
      	int m = sc.nextInt();
      	int x = sc.nextInt();
      	long books[][] = new long[n][m+1];
      	long uv[] = new long[m];
      	int np = (int)Math.pow(2,n);
      	int prc;
      	int prc_min = -1;
      	int istack;
      	boolean nb[] = new boolean[n];
      	boolean con;
      
      	for(int i = 0;i < n; i++){
          for(int j = 0;j < m+1; j++){
            books[i][j] = sc.nextLong();
          }
        }
      
      	for(int i = 0;i < np; i++){
          istack = i;
          for(int j = 0; j < n && istack > 0;j++){
          	  if(istack%2 == 1) {
                nb[j] = true;
              }
          	  else nb[j] = false;
          	  istack /= 2;
          }
          Arrays.fill(uv,0);
          prc = 0;
       	  for(int j = 0; j < n;j++){
            if(nb[j]){
              prc += books[j][0];
              for(int k = 1; k < m+1; k++){
              	uv[k-1] += books[j][k];
              }
            }          
          }
          con = true;
          for(int j = 0;j < m && con;j++){
            if(uv[j] < x) con = false;
          }
          if(con){
            if(prc_min == -1 || prc_min > prc) prc_min = prc;
          }
        }
	  
      	System.out.println(prc_min);
	}
}
