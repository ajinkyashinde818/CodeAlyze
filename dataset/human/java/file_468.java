import java.util.*;

class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		int N = Integer.parseInt(sc.next());
		int R = Integer.parseInt(sc.next());
	
		if(N >= 10) {
			System.out.println(R);
		} else {
			System.out.println(R+(100*(10-N)));
		}
	}

}
