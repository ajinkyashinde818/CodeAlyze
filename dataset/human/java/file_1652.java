import java.util.*;
import java.math.*;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// 整数の入
		int n = sc.nextInt();
		String s = sc.next();
		long bigValue = 1000000007;

		List<String> array = new ArrayList<String>();
		for(int i=0;i<n;i++){
			array.add(s.substring(i,i+1));
		}
		Collections.sort(array);
        // System.out.println(array);

		long sum =1;
		long prevA = 0;
		String prevS = array.get(0);

		for(int i=1;i<n;i++){
			String a = array.get(i);
			if(a.equals(prevS)){
				sum += 1 + prevA;
				// System.out.println("i="+i + ", sum="+sum);
			}else{
				prevA = sum;
				prevS = a;
				sum+= sum + 1;
				// System.out.println("i="+i + ", sum="+sum);
			}
			if(sum>bigValue){
				sum = sum%bigValue;
			}
		}
        System.out.println(sum%bigValue);
 
	}
}
