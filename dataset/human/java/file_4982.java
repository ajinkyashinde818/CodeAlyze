import java.util.Scanner;

public class Main {
    Scanner sc = new Scanner(System.in);

    public static void main(String[] arg){
        Main m = new Main();
        m.run();
    }

    void run(){
        String s = sc.next();
        int q = sc.nextInt();

        int direction = 1;

        StringBuilder sbf = new StringBuilder();
        StringBuilder sbb = new StringBuilder();

        for(int i = 0; i< q; i ++){
            int t = sc.nextInt();

            if(t == 1){
                direction = 3 - direction;
            }else{
                int f = sc.nextInt();
                String c = sc.next();

                if(direction != f ){
                    sbf.append(c);
                }else{
                    sbb.append(c);
                }
            }
        }

        sbb.reverse().append(s).append(sbf.toString());

        if(direction == 2){
            sbb.reverse();
        }

        System.out.println(sbb.toString());
    }
}
