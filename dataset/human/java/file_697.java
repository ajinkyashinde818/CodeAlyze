import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import java.util.HashSet;
import java.util.*;

public class Main {
		public static void main(String[] args) throws Exception{
			Scanner sc=new Scanner(System.in);
			PrintWriter pw= new PrintWriter(System.out);
			int n=sc.nextInt();
			int r=sc.nextInt();
			if(n>=10) {
				pw.println(r);
			}
			else {
				pw.println(r+(100*(10-n)));
			}
			
			
			sc.close();
			pw.close();
			
		}
	
	
}
