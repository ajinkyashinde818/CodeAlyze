import java.util.Scanner;
import java.util.Arrays;
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        
        String s=sc.next();
        int nums=s.length();
        String[] S=new String[nums];
        for(int i=0;i<nums;i++){
            S[i]=s.substring(i,i+1);
        }
        s="";
        Arrays.sort(S);
        for(int i=0;i<nums;i++){
            s+=S[i];
        }
        
        String t=sc.next();
        int numt=t.length();
        String[] T=new String[numt];
        for(int i=0;i<numt;i++){
            T[i]=t.substring(i,i+1);
        }
        t="";
        Arrays.sort(T);
        for(int i=0;i<numt;i++){
            t+=T[numt-i-1];
        }
        
        if(s.compareTo(t)<0){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}
