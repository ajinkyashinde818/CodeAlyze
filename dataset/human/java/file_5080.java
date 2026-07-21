import java.util.*;

public class Main {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        int q = sc.nextInt();

        StringBuilder sbL = new StringBuilder();
        StringBuilder sbR = new StringBuilder();

        boolean flag = false;

        int cnt = 0;

        for (int i=0; i<q; i++){
            int tmp = sc.nextInt();
            if (tmp==1){
                cnt++;
                flag = !flag;
            }else if (tmp==2){
                int tmpI = sc.nextInt();
                String tmpS = sc.next();
                if (tmpI==1){
                    if (flag){
                        sbR.append(tmpS);
                    }else {
                        sbL.append(tmpS);
                    }
                }else if (tmpI==2){
                    if (flag){
                        sbL.append(tmpS);
                    }else {
                        sbR.append(tmpS);
                    }
                }
            }
        }

        if (cnt%2==0){
            System.out.print(sbL.reverse().append(s).append(sbR).toString());
        }else {
            StringBuffer str = new StringBuffer(s);
            s = str.reverse().toString();
            System.out.print(sbR.reverse().append(s).append(sbL).toString());
        }

    }

}
