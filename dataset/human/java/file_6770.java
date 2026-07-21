import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {

//    	File file = new File("test.txt");
//    	Scanner sc = new Scanner(file);
    	Scanner sc = new Scanner(System.in);
    	int N = sc.nextInt();
    	int K = sc.nextInt();
    	int[] ary = new int[K];
    	int[] ary2 = new int[K];
     	for(int i = 0; i < K; i++){
    		ary[i] = sc.nextInt();
    		if(i > 0){
    			if(i <= K-1){
    				ary2[i-1] = ary[i] - ary[i-1];
    			}
    		}
    	}
    	ary2[K-1] = N - ary[K-1] + ary[0];
    	sc.close();
    	int ans = 0;
    	Arrays.sort(ary2);
    	for(int j = 0; j < K-1; j++){
    		ans += ary2[j];
    	}
    	System.out.println(ans);
	}
}
