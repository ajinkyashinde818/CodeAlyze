import java.util.Scanner;

class Main{

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int r = scanner.nextInt();
        scanner.close();
        if(n>9){
            System.out.println(r);
            return;
        }else{
            System.out.println(r+100*(10-n));
            return;
        }
    }
}
