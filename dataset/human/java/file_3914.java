import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n;

        while(true) {
            n = scan.nextInt();

            if(n==0) {
                break;
            }

            char tree[][] = new char[n][1501];
            for(int i=0;i<n; i++){
                for (int j=0; j<1501; j++){
                    tree[i][j] = '-';
                }
            }

            int s_max = 0;

            for (int i = 0; i < n; i++) {
                String s = scan.next();
                if(s.length()>s_max){
                    s_max = s.length();
                }
                for(int j=0; j<s.length(); j++){
                    tree[i][j] = s.charAt(j);
                }
            }

            int plus_row = 0;

            for(int j=0; j<s_max; j++){
                boolean plus_flag = false;
                for(int i=0; i<n; i++){
                    if (tree[i][j] == '.' && tree[i][j+1] != '.') {
                        tree[i][j] = '+';
                        plus_row = i;
                        plus_flag = true;
                    } else if(tree[i][j] == '.'){
                        tree[i][j] = '|';
                    } else if(tree[i][j] != '.' && plus_flag == true && tree[i-1][j] =='|'){
                        for(int k=plus_row+1; k<i; k++){
                            tree[k][j] = ' ';
                        }
                    }
                }

                if(tree[n-1][j] == '|'){
                    for(int k=plus_row+1; k<n; k++){
                        tree[k][j] = ' ';
                    }
                }
            }

            for(int i=0 ;i<n; i++){
                for(int j=0;j<s_max; j++) {
                    if(tree[i][j] == '-') {
                        break;
                    }
                    System.out.print(tree[i][j]);
                }
                System.out.println("");
            }
        }
    }
}
