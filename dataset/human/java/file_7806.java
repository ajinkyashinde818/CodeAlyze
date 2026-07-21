import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.Collections;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.ArrayList;

public class Main {

  public static void main(String[] args) throws IOException {
	  Scanner in = new Scanner(System.in);
	  int n = in.nextInt();
	  long k = in.nextLong();
	  int[] visit = new int[n];
	  int[] node = new int[n];
	  for(int i=0; i<n; i++) {
		  node[i]=in.nextInt();
	  }
	  int count = 0;
	  int current = 1;
	  long loop = k-1;
	  while(loop>0) {
		  count++;
		  if(visit[current-1]==0) {
			  visit[current-1]=count;
			  current = node[current-1];
			  //System.out.println(current);
		  }else {
			  int cycle = count-visit[current-1];
			  //System.out.println("count: "+count);
			  //System.out.println("cycle: "+cycle);
			  int remain = visit[current-1]-1;
			  //System.out.println("remain: "+remain);
			  long target = ((k-remain) % cycle);
			  //System.out.println("target: "+target);
			  for(int i=0; i<n; i++) {
				  if(visit[i]==target+1+remain) {
					  System.out.print(i+1);
					  System.exit(0);
				  }
			  }
		  }
		  loop--;	  
	  }
	  System.out.print(node[current-1]);
      
  }
}
