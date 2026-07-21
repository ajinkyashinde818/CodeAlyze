/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		int b = input.nextInt();
		int k = input.nextInt();
		
		ArrayList<Integer> list = new ArrayList<>();
		ArrayList<Integer> lists = new ArrayList<>();
		
		for(int i=1;i<=a;i++)
		    if(a%i==0)
		        list.add(i);
		        
		for(int i=1;i<=b;i++)
		    if(b%i==0)
		        lists.add(i);
		        
		ArrayList<Integer> List = new ArrayList<>();
		
		for(int t:list)
		{
		    if(lists.contains(t))
		        List.add(t);
		}
		Collections.sort(List,Collections.reverseOrder());
		
		//System.out.println(List);
		System.out.println(List.get(k-1));
		
	}
}
