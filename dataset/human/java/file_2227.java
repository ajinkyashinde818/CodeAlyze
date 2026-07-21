import java.util.*;
import java.util.function.*;
import java.math.*;
public class Main {
    public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		long N = s.nextLong();
		int maxs = (int)Math.sqrt(N);
		long[][] sosu = new long[maxs][3]; // 0=素因子, 1=累乗数, 2=割った回数
		
		int result = 0;
		
		// 素因氏分解を実施
		int index = 0;
		for(int i = 2; i < maxs; i++) {
			if(N%i==0) {
				sosu[index++][0] = i;
				sosu[index - 1][2] = 1;
				while(N%i==0) {
					sosu[index - 1][1] = sosu[index - 1][1] + 1;
					N /= i;
				}				
			}
		}
		if(N > 1) {
			sosu[index][0] = N;
			sosu[index][1] = 1;
			sosu[index][2] = 1;
			
		}
		
		// 素数の中身をみていく
		for(int i = 0; i < maxs; i++) {
			if(sosu[i][0] == 0)
				break;
			
			while(sosu[i][1] - sosu[i][2] > -1) {
				sosu[i][1] = sosu[i][1] - sosu[i][2];
				sosu[i][2] = sosu[i][2] + 1;
				result++;
			}
		}
		
		System.out.println(result);
    }
}
