//intのオーバーフローに気をつけろ,AGCはだいたいlongにしておけ
//毎回余りを求めることでオーバーフローしなくなる
//nextLineよりnextだ
//charは''で囲うんだぞ
//読み込みは先に全部やっておけ
//for文を回す回数に気をつけろ

import java.util.Scanner;

public class Main {

	public static void main(String args[]) throws InterruptedException {
		    Scanner sc = new Scanner(System.in);
		    
		    int x = sc.nextInt();
		    int wa = sc.nextInt();
		    int ans = 0;
		    
		    for(int i = 0; i <= x;i++) {
		    	for(int j = 0; j <= x; j++) {
		    		if(0 <= wa-i-j && wa-i-j <= x ) {
		    			ans++;
		    		}
		    	}
		    }
		    System.out.println(ans);
		    sc.close(); }

	public static void saiki(int a, String b) {
		//再帰コーディングのお手本

		if(a == 0) {
			System.out.println(b);
		}else {
			for(char ch = 'a'; ch <= 'c'; ch++) {
				saiki(a-1,b + ch);
			}
		}
	}

	public static  int gcd(int a, int b) {
	    if (a < b) {
	        int tmp = a;
	        a = b;
	        b = tmp;
	    }

	    int r = -1;
	    while (r != 0) {
	        r = a % b;
	        a = b;
	        b = r;
	    }

	    return a;
	}
}
