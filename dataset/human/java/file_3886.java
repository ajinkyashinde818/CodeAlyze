import java.util.*;
import java.io.*;

public class Main {
    public static boolean isPalindrome(String s){
        int L = s.length();
        boolean ans = true;
        for(int l=0;l<L/2;l++){
        	if(s.charAt(l)!=s.charAt(L-1-l)) ans = false;
        }
        return ans;
    }
    public static int calculate(String given){
        int L = given.length();
        if(L<=1) return 0;
        int i=0;
        int j=L-1;
        int ans = 0;
        while(i<j){
        	if(given.charAt(i)==given.charAt(j)){
        	    i++;
        	    j--;
        	}
        	else if(given.charAt(i)=='x'){
                i++;
                ans++;
        	}
        	else{
        	    j--;
        	    ans++;
        	}
        	
        }
        return ans;
    }
    public static int solve(String given){
    	String copy = new String(given);
    	if(!isPalindrome(copy.replaceAll("x",""))) return -1;
    	return calculate(given);
    	
    }	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String given = sc.next();
        System.out.println(solve(given));
    }
}
