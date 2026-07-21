import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        
        String s = scan.next();
        String t = scan.next();
        
        char[] ss = new char[s.length()];
        char[] tt = new char[t.length()];
        
        for(int i=0;i<s.length();i++)
        {
            ss[i] = s.charAt(i);
        }
        
        for(int i=0;i<t.length();i++)
        {
            tt[i] = t.charAt(i);
        }
        
        Arrays.sort(ss);
        Arrays.sort(tt);
      
      	int len = Min(ss.length,tt.length);
        
        for(int i=0;i<len;i++)
        {
            if(ss[i]<tt[tt.length-i-1])
            {
                System.out.println("Yes");
                return;
            }
            else if(ss[i]==tt[i])
            {
                continue;
            }
            else
            {
                System.out.println("No");
                return;
            }
        }
        
        if(s.length()<t.length())
        {
            System.out.println("Yes");
            
        }
        else
        {
            System.out.println("No");
        }
    }
  
  	static int Min(int a,int b){
      	int min = a;
      	if(b<a)
        {
			min = b;
        }
      	return min;
  	}
}
