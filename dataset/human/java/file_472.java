import java.util.*;

class Main {

    public Main(){
        Scanner SC = new Scanner(System.in);
        int N = SC.nextInt();
        int R = SC.nextInt();

        if(N >= 10){
            System.out.println(R);
        } else {
            System.out.println(R+100*(10-N));
        }
    }

    public static void main(String[] args){
        Main main = new Main();
    }
}
