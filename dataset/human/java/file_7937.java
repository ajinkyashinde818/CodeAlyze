import java.util.*;

public class Main {
	Scanner sc = new Scanner(System.in);
	
	private void doit(){
		while(sc.hasNext()){
			int sum = 0;
			for(int i = 0; i < 10; i++){
				sum += sc.nextInt();
			}
			System.out.println(sum);
		}
	}

	private void debug(Object... o) {
		System.out.println("debug = " + Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().doit();
	}
}
