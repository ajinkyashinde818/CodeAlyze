import java.util.*;

public class Main {// Main
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
      int n =(int) sc.nextLong();
     int m =(int) sc.nextLong();
      long x =sc.nextLong();
      
      
      long [][] arr =  new long[n][m+1];
      for(int i = 0 ; i < n ; i++) {
    	  for(int j = 0 ;  j <= m ; j++) {
    		  arr[i][j] = sc.nextLong();
    	  }
      }
     
      long min =Long.MAX_VALUE ;
      for(int i =  0 ;  i < Math.pow(2, n ) ; i++) {
    	  long[] temp = new long[m+1];
    	  int t = i ;
    	  for(int j = 0  ; j <n;j++) {
    		  if((t>>j &1) ==1) {
    			  for(int k = 0 ; k<temp.length ; k++ ) {
    				  temp[k]+=arr[j][k];
    			  }
    		  }
    	  }
    	  if(check(temp , x)) {
    		  min = Math.min(min, temp[0]);
    	  }
       }
      if(min==Long.MAX_VALUE) {
    	  System.out.println(-1);
      }else
       System.out.println(min);
	}

	private static boolean check(long[] temp, long x) {
		// TODO Auto-generated method stub
		 
		for(int i = 1 ;i< temp.length ; i++) {
			if(temp[i] < x) {
				return false;
			}
		}
		return true;
	}
}
