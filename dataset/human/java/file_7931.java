import java.util.*;
public class Main {
	Scanner in = new Scanner(System.in);
	public static void main(String[] args) {
		new Main();
	}

	public Main(){
		new AOJ0256().doIt();
	}
	class AOJ0256{
		void doIt(){
			while(in.hasNext()){
				int sum = 0;
				for(int i=0;i<10;i++)sum+=in.nextInt();
				System.out.println(sum);
			}
		}
	}
}
