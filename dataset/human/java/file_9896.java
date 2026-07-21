import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int ans = 10000000;
		int [] [] in = new int [n][m+1];
       
        for(int i=0;i<n;i++){
                             for(int j=0;j<=m;j++){in[i][j] = sc.nextInt();}
                            }
        int max = 1;
        for(int i=0;i<n;i++){max*=2;}
        max--;
        int [] check = new int [n];  
        for(int i=0;i<=max;i++){int p = i; int cost = 0; int bool = 0;
                                for(int j=0;j<n;j++){check[j]=p%2;p/=2;}
                                for(int j=0;j<n;j++){cost+=in[j][0]*check[j];}
                                for(int j=1;j<=m;j++){int skill=0;
                                                      for(int k=0;k<n;k++){skill+=in[k][j]*check[k];}
                                                      if(skill<x){bool=1;}
                                                     }
                               if(bool==0){ans=Math.min(ans,cost);}
                               }        
        if(ans==10000000){ans=-1;}
		System.out.println(ans);
}
}
