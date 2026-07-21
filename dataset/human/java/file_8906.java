import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeSet;

import org.omg.Messaging.SyncScopeHelper;

public class Main {
	Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		new Main();
	}
	public Main(){
		new Test_200().doIt();
	}
	class Test_200{
		void doIt() {
			int A = sc.nextInt();
			int B = sc.nextInt();
			int K = sc.nextInt();
			for(int i = 100;i >= 1;i--) {
				if(A % i == 0 && B % i == 0)K = K - 1;
				if(K == 0) {
					System.out.println(i);
					break;
				}
			}
		}
	}
}
