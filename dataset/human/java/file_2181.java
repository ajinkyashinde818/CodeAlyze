import java.util.*;
import java.io.*;
 
public class Main{
    
	public static void main(String[] $){
		Scanner s = new Scanner(System.in);
		long N = s.nextLong();
		long N2 = N;
		int count = 0;
		int[] sosu = new int[1000000];
		int sosusount = 0;
		int i = 2;
		while(i <= 1000000){
			while(N%i == 0L){
				N = N/i;
				sosu[sosusount]++;
			}
			i++;
			sosusount++;
		}
		for(int j = 0; j < 1000000; j++){
			int aCount = 1;
			while(sosu[j] >= aCount){
				count++;
				sosu[j] = sosu[j] - aCount;
				aCount++;
			}
		}
		
		if(count == 0 && N == 1L){
			System.out.println(0);
		}else if(N != 1L){
			System.out.println(count+1);
		}else{
			System.out.println(count);
		}
		
	}
}
