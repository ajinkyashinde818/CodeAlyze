/*
 *ver3
 *可変長配列を使わない
 */

import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);
	
	int n = scan.nextInt();
	int[] a = new int[n];

	long sum = 0;
	int count = 0;
	for(int i = 0; i < n; i++){
	    a[i] = scan.nextInt();
	    if(a[i] < 0){
		count++;
		a[i] = Math.abs(a[i]);
	    }
	    sum += a[i];
	}

	Arrays.sort(a);

	if(count % 2 == 0){
	    System.out.println(sum);
	}else{
	    System.out.println(sum - a[0]*2);
	}
    }
}
