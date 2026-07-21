import java.util.*;
public class Main{
    public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int m = sc.nextInt();
      int x = sc.nextInt();
      int[] cost = new int[n];
      int[][] value = new int[n][m];
      for(int i=0;i<n;i++){
      	cost[i]=sc.nextInt();
      	for(int j=0;j<m;j++){
      		value[i][j]=sc.nextInt();
      	}
      }
      int resultsum=Integer.MAX_VALUE;
      int flag =0;
      for(int i=0;i<(1<<n);i++){
      	int curr =0;
      	int[] currsum= new int[m];
      	for(int j=0;j<n;j++){
      		if(((i>>j)&1)==1){
      			curr = curr+cost[j];
      			for(int k=0;k<m;k++){
      				currsum[k]=currsum[k]+value[j][k];
      			}
      		}
      	}
      	if(check(currsum,x)){
      		flag=1;
      		resultsum= Math.min(resultsum,curr);
      	}
      }
      if(flag==0){
      	System.out.println(-1);
      	return;
      }
      System.out.println(resultsum);
}
public static boolean check(int[] arr, int x){
	for(int i=0;i<arr.length;i++){
		if(arr[i]<x){
			return false;
		}

	}
	return true;
}
}
