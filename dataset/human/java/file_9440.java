import java.util.*;
import java.util.Scanner;

public class Main {
	
	public static void funct(int[][] arr) {
		int[] t=new int[arr.length];
		for(int i=0;i<arr.length;i++) {
			t[i]=arr[i][1]-arr[i][0];
		}
		int c=0;
		for(int i=1;i<arr.length-1;i++) {
			if(t[i]==0 && t[i-1]==0 && t[i+1]==0) {
				c++;
			}
		}
		if(c>=1) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[][] arr=new int[n][2];
		for(int i=0;i<n;i++) {
			int[] temp=new int[2];
			temp[0]=sc.nextInt();
			temp[1]=sc.nextInt();
			arr[i]=temp;
		}
		funct(arr);
	}

}
