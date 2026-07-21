import java.util.Scanner;


public class Main {
    static Scanner s = new Scanner(System.in);
    static char[][] word;

    public static void main(String[] args) {
        while (true) {
            int n = s.nextInt();
            if (n == 0) break;

            word = new char[n][];

            for(int i=0;i<n;i++) {
                String str = s.next();
                word[i] = new char[str.length()];
                for (int j = 0; j < str.length(); j++) {
                    word[i][j] = str.charAt(j);
                }
            }

            int posi=-1;
            for(int i=1;i<n;i++){
                int nowPosi=-1;
                for(int j=0;j<word[i].length;j++) {
                    if (word[i][j]=='.'){
                        nowPosi++;
                    }else {
                        if(posi<=nowPosi){
                            if(posi>=0) {
                                word[i - 1][posi] = '+';
                                chenge(i - 1, posi);
                            }
                            word[i][nowPosi]='+';
                        } else if(posi>nowPosi){
                            word[i-1][posi]='+';
                            chenge(i-2,posi);
                            posi--;
                            while(posi>nowPosi){
                                brank(i-1,posi);
                                posi--;
                            }

                            if(nowPosi>=0) {
                                word[i][nowPosi] = '+';
                                chenge(i - 1, nowPosi);

                            }else{
                                while(posi>nowPosi){
                                    brank(i-1,posi);
                                    posi--;
                                }
                            }
                        }
                        break;
                    }
                }
                posi=nowPosi;
            }
            while(posi>=0){
                brank(n-1,posi);
                posi--;
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<word[i].length;j++) {
                    System.out.print(word[i][j]);
                }
                System.out.println();
            }
        }
    }

    public static void chenge( int n, int m){
        for(int i=n;;i--){
            if(word[i][m]=='.') word[i][m]='|';
            else break;
        }
    }

    public static void brank(int n, int m){
        for(int i=n;;i--){
            if(word[i][m]=='+') break;
            else word[i][m]=' ';
        }
    }
}
