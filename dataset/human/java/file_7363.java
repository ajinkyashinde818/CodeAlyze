import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) throws Exception{    
        Scanner sc = new Scanner(System.in);
        // code
       
        String s = sc.next();
        
        int ans = func(0, s, s.length());
        
        
        if(ans  >= 1){
        	System.out.println("YES");
        }else{
        	System.out.println("NO");
        }
        
        sc.close();
    }
        
    static int func(int i, String s, int len){
    	int ans = 0;
    	
    	if(len - i <= 7){
    		if(len - i == 5){
            	if(s.substring(i, i+5).equals("dream")) ans += 1;
            	if(s.substring(i, i+5).equals("erase")) ans += 1;
            }else if(len - i == 6){
            	if(s.substring(i, i+6).equals("eraser")) ans += 1;
            }else if(len - i == 7){
            	if(s.substring(i, i+7).equals("dreamer")) ans += 1;
            }
    	}else if(s.substring(i, i+5).equals("dream")){
    		ans += func(i+5, s, len);
    		if(s.substring(i, i+7).equals("dreamer")) ans += func(i+7, s, len);
    	}else if(s.substring(i, i+5).equals("erase")){
    		ans += func(i+5, s, len);
    		if(s.substring(i, i+6).equals("eraser")) ans += func(i+6, s, len);
    	}
    	return ans;
    }
    
    
    
    
 
}
