import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner stdIn=new Scanner(System.in);

        int N=stdIn.nextInt();
        int R=stdIn.nextInt();

        if(N>=10){
            System.out.println(R);
            
        }
        else{
            System.out.println(R+100*(10-N));
            
        }
        
        
    }

}
