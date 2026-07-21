import java.io.*;
import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner inputs = new Scanner(System.in);
		int total = inputs.nextInt();
		int houses = inputs.nextInt();
		int maxgap = -1;
		int dist = 0;
		int first = inputs.nextInt();
		int prev = first;
		int num=0;
		for(int i=1;i<houses;i++) {
			num = inputs.nextInt();
			dist+=num-prev;
			maxgap = Math.max(maxgap, num-prev);
			prev=num;
		}
		if(num!=0)
			dist+= first+total-num;
		maxgap = Math.max(maxgap, first+total-num);
		dist-=maxgap;
		System.out.println(dist);
	}

}
