/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class Main {
	public static void main (String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int k = sc.nextInt();
	    int n = sc.nextInt();
	    int arr[]=new int[n];
	    for(int i=0;i<n;i++) arr[i]=sc.nextInt();
	    long res= k+arr[0]-arr[n-1];
	    for(int i=1;i<n;i++) res=Math.max(res,arr[i]-arr[i-1]);
		System.out.println(k-res);
	}
}
