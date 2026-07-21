import java.awt.*;
import java.io.*;
import java.util.*;
 
public class Main {
	Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		new Main();
	}
	public Main(){
		new TestB().doIt();
	}
	class TestB{
		void doIt() {
			int N = sc.nextInt();
			int cnt = 0;
			boolean renzoku3 = false;
			for(int i = 0;i < N;i++) {
				int D1 = sc.nextInt();
				int D2 = sc.nextInt();
				if(D1 == D2) {
					cnt++;
				}else {
					cnt = 0;
				}
				if(cnt >= 3) {
					renzoku3 = true;
				}
			}
			if(renzoku3)System.out.println("Yes");
			else System.out.println("No");
		}
	}
}
