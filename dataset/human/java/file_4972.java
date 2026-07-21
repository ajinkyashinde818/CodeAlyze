import java.util.Scanner;

public class Main {
    public static void debug(String str) {
        System.out.println(str);
    }

    public static void main(String[] args) {

        String S;
        long Q;
        StringBuilder sbFist = new StringBuilder();
        StringBuilder sbSecond = new StringBuilder();
        boolean traverse = false;

        try (Scanner sc = new Scanner(System.in)) {
            S = sc.next();
            Q = sc.nextLong();
            for(int i= 0;i < Q;i++){
                if(sc.nextInt() == 1){
                    //反転
                    traverse = !traverse;
                }else{
                    //文字列加える
                    if(!((sc.nextInt() == 1) ^ (!traverse))){
                        //前に
                        sbFist.append(sc.next());
                    }else{
                        sbSecond.append(sc.next());
                    }
                }
            }
        }
        String result;
        if(!traverse){
            result = sbFist.reverse().append(S).append(sbSecond).toString();
        }else {
            StringBuilder temp = new StringBuilder(S);
            result = sbSecond.reverse().append(temp.reverse()).append(sbFist).toString();
        }
        System.out.println(result);
        return;
    }
}
