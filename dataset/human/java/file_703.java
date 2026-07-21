import java.util.Scanner;
             
        public class Main {
        	public static void main(String[] args) {
                Scanner scan = new Scanner(System.in);
                String[] str = scan.nextLine().split(" ");
                Integer joinCount = new Integer(str[0]);
                Integer displayCount = new Integer(str[1]);
                Integer internalCount = 0;
                if(joinCount >= 10){
                  internalCount = displayCount;
                }else{
                  internalCount = (100*(10-joinCount))+displayCount;
                }
             	
                System.out.println(internalCount);
                scan.close();
            }
        }
