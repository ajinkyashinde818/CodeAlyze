//package javaapplication2;
import java.util.*;
import java.io.*;
import static java.lang.System.out;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        StringBuilder res = new StringBuilder();
        int rev = 0,rev_2 = 0;
        int Q = Integer.parseInt(br.readLine());
        char[] forward = new char[Q];
        int ptr1 = Q-1,ptr2 = Q-1;
        char[] backward = new char[Q];
        
        
        
        while(Q-- > 0){
            String[] s2 = br.readLine().split("\\s");
            if(s2[0].equals("1")){
                rev_2 ^= 1;
            }else{
                if(s2[1].equals("1")){
                    if(rev_2 == 0) forward[ptr1--] = s2[2].charAt(0);
                    else backward[ptr2--] = s2[2].charAt(0);
                }else{
                     if(rev_2 == 0) backward[ptr2--] = s2[2].charAt(0);
                    else forward[ptr1--] = s2[2].charAt(0);
                }
            }
        }
            
        
        while(++ptr1 < forward.length) res.append(forward[ptr1]);
        res.append(s);
        for(int i = backward.length-1;i>ptr2;--i) res.append(backward[i]);
        
        
        if(rev_2 == 1) System.out.println(res.reverse().toString());     
        else System.out.println(res.toString());        
    }
    
//    private static int solve(int A,int B){
//      
//    }
}
