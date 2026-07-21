import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
    Scanner scn= new Scanner(System.in);
    long k=scn.nextLong();
    int n =scn.nextInt();
    long [] arr =new long[n];
    for(int i=0;i<n;i++){
    	arr[i]=scn.nextLong();
    	
    }
    long max=0;
    for(int i=1;i<arr.length;i++){
      max=Math.max(Math.abs(arr[i-1]-arr[i]),max);
      
    }
    max = Math.max((Math.abs(arr[arr.length-1]-(arr[0]+k))), max);
    System.out.println(Math.abs(k-max));
    }

}
