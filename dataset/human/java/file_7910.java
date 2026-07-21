import java.util.*;
public class Main {
	static Scanner sc = new Scanner(System.in);
	static int res;
	public static void main(String[] args) {
		while(read()){
			solve();
		}
	}
	
	static boolean read(){
		if( !sc.hasNext() )return false;
		for(int i = 0; i < 10; i++){
			res += sc.nextInt();
		}
		return true;
	}
	
	static void solve(){
		System.out.println(res);
	}

}
