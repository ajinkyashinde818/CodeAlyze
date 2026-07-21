import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		
		int count[] = new int[100003];
		
		for(int i = 0; i < n; i++){
			String[] tmpArray = br.readLine().split(" ");
			
			int a = Integer.parseInt(tmpArray[0]);
			int b = Integer.parseInt(tmpArray[1]);
			
			count[a]++;
			count[b + 1]--;
		}
		
		//debug
//		for(int i = 0; i <= 10; i++){
//			System.out.print(count[i]+" ");
//		}
//		System.out.println();
		
		int sum[] = new int[count.length];
		for(int i = 2; i < count.length; i++){
			sum[i] = sum[i - 1] + count[i];
			
//			if(i >= 4950 && i <= 5000) System.out.print("i = "+i+" sum="+sum[i] + " ");
		}
//		System.out.println();
		
		int index = 1;
		int maxValue = 0;
		
		for(int i = 2; i <= n + 1; i++){
//			System.out.println("sum "+sum[i]);
//			result = Math.max(result, sum[i]);
			
			if(maxValue <= sum[i] && sum[i] >= i - 1){
//				System.out.println("update at i = "+i);
				maxValue = i;
				index = i;
			}
		}
		
		System.out.println(index - 1);
	}

}
