import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
           int i ;
           int s ;
           int dog = 0;
           for(i = 0 ; i<10;i++){
               s = scan.nextInt();
               dog += s;
           }
           System.out.println(dog);

        }

    }
