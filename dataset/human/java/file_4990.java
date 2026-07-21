import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class Main {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args){

		solve_abc158_d();
	}
  
  	public static void solve_abc158_d(){

		Scanner sc = new Scanner(System.in);

		
		StringBuilder sb = new StringBuilder(sc.next());
		StringBuilder front = new StringBuilder();
		StringBuilder bak = new StringBuilder();
		
		int q = sc.nextInt();
		
		boolean rev = false;
		
		for(int i=0;i<q;i++){
			
			int t = sc.nextInt();
			
			if(t == 1){
				rev = !rev;
			}
			else if(t == 2){
				int f = sc.nextInt();
				
				
				if((f == 1 && !rev ) || (f == 2 && rev)){
					/*
					StringBuilder sbtmp = new StringBuilder(sc.next());
					sbtmp.append(sb);
					sb = sbtmp;
					*/
					//sb.insert(0, sc.next());
					
					front.append(sc.next());
				}
				else {
					bak.append(sc.next());
					//sb.append(sc.next());
				}
			}
		}
		
		front.reverse();
		front.append(sb).append(bak);
		
		if(rev) front.reverse();
		
		System.out.println(front);

		sc.close();

	}
}
