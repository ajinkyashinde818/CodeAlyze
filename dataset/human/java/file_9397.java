import java.util.*;
import java.io.*;
import java.math.BigInteger;
 
public class Main {
	public static long mod = 1000000007;
	
	public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	int N = s.nextInt();
	boolean is = false;
	int[][] D = new int[N][2];
	for(int i = 0; i < N; i++){
		D[i][0] = s.nextInt();
		D[i][1] = s.nextInt();
	}

	for(int i = 0; i < N-2; i++){
		if((D[i][0]==D[i][1]) && (D[i+1][0]==D[i+1][1]) && (D[i+2][0]==D[i+2][1])){
			is = true;
		}
	}
	if(is){
		System.out.println("Yes");
	}else{
		System.out.println("No");
	}
	
    
  }
}
