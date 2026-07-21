import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        int x = (int)Math.min(a, b);
        while(true){
        	if(a%x==0 && b%x==0){
        		k--;
        		if(k<1){
        			break;
        		}
        	}
        	x--;
        }
        System.out.println(x);
    }
}
