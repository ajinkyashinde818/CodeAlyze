import java.util.*;
import java.util.function.*;
import java.math.*;
public class Main {
    public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		int K = s.nextInt();
		int S = s.nextInt();
		
		int count = 0;
		for(int i = 0; i < K + 1; i++) {
			if(i > S)
				break;
			for(int j = 0; j < K + 1; j++) {
				if(0 <= S - i - j && S - i - j <= K)
					count++;
			}
		}
		
		System.out.println(count);
    }
}
