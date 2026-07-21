import java.util.*;
import java.lang.Math;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
      	
      	int n = sc.nextInt();
      	int m = sc.nextInt();
      	int dif = n-m+1;
        boolean ams[][] = new boolean[n][n];
      	boolean bms[][] = new boolean[m][m];
      	boolean con;
      	boolean nex;
      	String sstack;
      
      	for(int i = 0;i < n;i++){
          sstack = sc.next();
          for(int j = 0;j < n;j++){
          	if(sstack.charAt(j) == '#') ams[i][j] = true;
            else ams[i][j] = false;
          }
        }
      	for(int i = 0;i < m;i++){
          sstack = sc.next();
          for(int j = 0;j < m;j++){
          	if(sstack.charAt(j) == '#') bms[i][j] = true;
            else bms[i][j] = false;
          }
        }
      
      	nex = true;
      	for(int i = 0;i < dif && nex;i++){
          for(int j = 0;j < dif && nex;j++){
            con = true;
            for(int k = 0;k < m && con;k++){
          	  for(int l = 0;l < m && con;l++){
                if(ams[i+k][j+l] != bms[k][l]) con = false;
              }
            }
            if(con) nex = false;
          }
        }
      	
      
      	if(nex) System.out.println("No");
      	else System.out.println("Yes");
        
	}
}
