import java.util.Scanner;
import java.io.*;
import java.util.*;

public class Main {

	public static void main(String args[]){

		Scanner scan = new Scanner(System.in);
		StringBuffer sb = new StringBuffer(scan.next());
		StringBuffer sb1 = new StringBuffer("");
		int n = scan.nextInt();
		boolean reverse = false;

		for(int i = 0; i < n; i++){

			if(scan.nextInt() == 1)reverse = !reverse; 

			else if(reverse){
				if(scan.nextInt() == 1)sb.append(scan.next());
				else sb1.append(scan.next());
			}
			
			else{
				if(scan.nextInt() == 2)sb.append(scan.next());
				else sb1.append(scan.next());
			}

		}

		if(!reverse){
			System.out.println(sb.insert(0, sb1.reverse().toString()).toString());
		}
		else{
			System.out.println(sb.reverse().append(sb1.toString()).toString());			
		}

	}
}
