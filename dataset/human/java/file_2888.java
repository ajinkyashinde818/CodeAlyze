import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class Main{

	Scanner sc;

	static final int INF=1<<28;
	static final double EPS=1e-9;

	void run(){
		sc=new Scanner(System.in);
		for(; sc.hasNext();){
			int[] c={4, 1, 4, 1, 2, 1, 2, 1};
			int[] p=new int[8];
			for(int i=0; i<8; i++)
				p[i]=sc.nextInt();
			int min=Integer.MAX_VALUE;
			LinkedList<String> list=new LinkedList<String>();
			for(int j=0; j<8; j++){
				int sum=0;
				for(int i=0; i<8; i++)
					sum+=max(c[(i+j)%8]-p[i], 0);
				if(sum<=min){
					if(sum<min)
						list.clear();
					String s="";
					for(int i=0; i<7; i++)
						s+=c[(i+j)%8]+" ";
					s+=c[(7+j)%8];
					list.add(s);
					min=sum;
				}
//				println(sum+"");
			}
//			println("");
			String[] ss=list.toArray(new String[0]);
			sort(ss);
			println(ss[0]);
		}
		sc.close();
	}

	void print(String s){
		System.out.print(s);
	}

	void println(String s){
		System.out.println(s);
	}

	public static void main(String[] args){
		new Main().run();
	}
}
