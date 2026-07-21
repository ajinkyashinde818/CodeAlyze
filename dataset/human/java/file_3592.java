import java.util.*;

class Main {
    
    static Map<String, Integer> map = new HashMap() {
        {
            put("A",10);
            put("B",11);
            put("C",12);
            put("D",13);
            put("E",14);
            put("F",15);
        }
    };
    
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		String line = scanner.nextLine();
		
        String arr[] = line.split(" ", 0);
        
        int X = map.get(arr[0]);
        int Y = map.get(arr[1]);
        
        if (X<Y) {
            System.out.println("<");
        } else if(X>Y) {
            System.out.println(">");
        } else {
            System.out.println("=");
        }
	}
}
