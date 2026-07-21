import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        if(!isPalindrome(s.replace("x",""))){
            System.out.println(-1);
            System.exit(0);
        }
        ArrayList<Integer> rec = new ArrayList<>();
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s.charAt(i)!='x') rec.add(i);
        }

        long ans = 0;
        if(rec.size()!=0){
            ans += Math.abs(n-1-rec.get(rec.size()-1)-rec.get(0));
            int flag = 1-rec.size()%2;
            for(int i=0;i<rec.size()/2-flag;i++){
                int left = rec.get(i+1)-rec.get(i);
                int right = rec.get(rec.size()-1-i)-rec.get(rec.size()-2-i);
                ans += Math.abs(left-right);
            }
        }
        System.out.println(ans);
    }
    static boolean isPalindrome(String s){
        if(s.length()==0) return true;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s.charAt(i)!=s.charAt(n-1-i)) return false;
        }
        return true;
    }
}
