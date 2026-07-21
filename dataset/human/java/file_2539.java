import java.util.Scanner;
import java.util.Arrays;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();
        
        Arrays.sort(s);
        Arrays.sort(t);
        
        
        for(int i=0; i<Math.min(s.length,t.length); i++){
            if(s[i]<t[t.length-i-1]){
                System.out.println("Yes");
                return;
            }else if(s[i]==t[t.length-i-1]){
                continue;
            }else{
                System.out.println("No");
                return;
            }
        }
        
        if(s.length<t.length){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
        
        
        
        
        
        
          
        }
    }
