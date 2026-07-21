import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static BufferedReader reader;
	//static field here
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		reader = new BufferedReader(new InputStreamReader(System.in));
		//code here
		String[] strings = readLine();
		long N = Long.parseLong(strings[0]);
		int c2 = 0;
		long c5 = 0;
		if(N%2==1) {
			print(0);
		}else {
			long t = N/10;
			/*while(t>0) {
				c2+=t;
				t/=2;
			}
			t = N;*/
			while(t>0) {
				c5+=t;
				t/=5;
			}
			print(c5);
		}
		
		//String[] s = readLine();
		//print(num);
	}
	
	//functions here
	//note that all methods should be STATIC

	private static String[] readLine(){
		try{
			return reader.readLine().split(" ");
		}catch(Exception e){
			e.printStackTrace();
			return new String[]{e.getMessage()};
		}
	}
	private static void print(Object o){
		System.out.println(o);
	}
	private static void print(){
		System.out.println();
	}
}
