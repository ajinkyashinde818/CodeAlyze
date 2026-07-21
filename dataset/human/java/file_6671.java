import java.util.*;

public class Main {
	
	private void doit(){
		
		
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int n = sc.nextInt();
			int [] data = new int[n];
			long sum = 0;
			long nsum = 0;
			for(int i = 0; i < n; i++){
				data[i] = sc.nextInt();
				sum += data[i];
				nsum += i + 1;
			}
			if(sum % nsum !=  0){
				System.out.println("NO");
				continue;
			}
			
			int [] diff = new int[n];
			for(int i = 0; i < n; i++){
				diff[i] = data[(i + 1) % n] - data[i];
			}
			
			long res = 0;
			boolean flg = false;
			for(int i = 0; i < n; i++){
				long temp = (sum / nsum + diff[i] * -1);
				if(temp % n  != 0 || temp / n < 0){
					flg = true;
					break;
				}
				res += (temp/ n);
			}
			if(res == sum /nsum && !flg){
				System.out.println("YES");
			}
			else{
				System.out.println("NO");
			}
			
			
		}

	}

	private void debug(Object... o) {
		System.out.println("debug = " + Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().doit();
	}

}
