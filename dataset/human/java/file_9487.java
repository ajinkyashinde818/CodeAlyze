import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
    
		int shakeNum = sc.nextInt();
      
      	int counter = 0;
      
      	String rt = "No";
      
      	for(int i = 0; i < shakeNum; i++) {
        	int num1 = sc.nextInt();
        	int num2 = sc.nextInt();
          
          	if(num1 == num2) {
            	counter += 1;
              	if(counter >= 3) {
                	rt = "Yes";
                  	break;
                }
            } else {
            	counter = 0;
            }
        }
    	System.out.println(rt);
    }
}
