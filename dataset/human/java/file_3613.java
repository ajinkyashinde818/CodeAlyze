import java.util.*;
 
public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
      	String x = sc.next();
      	String y = sc.next();
		Map<String, Integer> map = new HashMap<>();
      	map.put("A", 10);
      	map.put("B", 11);
      	map.put("C", 12);
      	map.put("D", 13);
      	map.put("E", 14);
      	map.put("F", 15);
      	
      	if(map.get(x) < map.get(y)) {
        	System.out.println("<");  
        } else if(map.get(x) > map.get(y)) {
        	System.out.println(">");  
        } else {
         	System.out.println("=");
        }
    }
}
