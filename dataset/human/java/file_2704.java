import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
      	String s = sc.next();
        String t = sc.next();
      	char ss[] = s.toCharArray();
    	char ts[] = t.toCharArray();
      	char trs[] = new char[t.length()];
      
      	Arrays.sort(ss);
      	Arrays.sort(ts);
      	
      	for(int i = 0;i < t.length();i++) trs[i] = ts[t.length()-1-i];
      
      	s = new String(ss);
      	t = new String(trs);
          
      	if(s.compareTo(t) < 0) System.out.println("Yes");
      	else System.out.println("No");
      
	}
}
