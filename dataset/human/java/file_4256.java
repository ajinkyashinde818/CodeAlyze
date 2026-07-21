import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main { 
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	String gomi = sc.nextLine();
    	String[] eatingOrder = sc.nextLine().split(" ");
    	String[] satsfCount = sc.nextLine().split(" ");
    	String[] addiconlSatsf  = sc.nextLine().split(" ");
    	int[] intEaOrder = new int[eatingOrder.length];
    	int[] intSatsCount = new int[satsfCount.length];
    	
    	int tempPre = -1;
    	List additional = new ArrayList<Integer>(); 
    	int result = 0;
    	for(int i = 0;i<eatingOrder.length;i++) {
    		intEaOrder[i] = Integer.parseInt(eatingOrder[i]);
    		intSatsCount[i] = Integer.parseInt(satsfCount[i]);
    		if(tempPre+1 == intEaOrder[i]) {
    			additional.add(tempPre);
    		}
    		tempPre = intEaOrder[i];
    		result += intSatsCount[i];
    		
    	}
    	
    	for(int i = 0;i<additional.size();i++) {
    		int tmp = (int) additional.get(i);
    		result += Integer.parseInt(addiconlSatsf[tmp-1]);
    	
    	}
    	System.out.println(result);
    	
    	
    	
    	
    }
}
