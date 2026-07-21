import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int count[] = new int[n];
        for (int i = 1;i <= 447;++i){
            if((i * i + i) / 2 == n){
                int res[][] = new int[i + 1][i];
                int field[] = new int[n];
                for (int j = 0;j < n;++j){
                    field[j] = -1;
                }
                for (int j = 0;j < i;++j){
                    res[0][j] = j;
                    field[j] = 0;
                    ++count[j];
                }
                for (int j = 1; j < i + 1;++j){
                    boolean ps[] = new boolean[i + 1];
                    int c = 0;
                    for (int k = 0;k < n;++k){
                        if(count[k] == 2)continue;
                        if(field[k] >= 0){
                            if(ps[field[k]])continue;
                            res[j][c] = k;
                            ps[field[k]] = true;
                            field[k] = j;
                            ++count[k];
                            ++c;
                        }
                        else{
                            res[j][c] = k;
                            field[k] = j;
                            ++count[k];
                            ++c;
                        }
                        if(c == i)break;
                    }
                }
                System.out.println("Yes");
                System.out.println(i + 1);
                StringBuilder sb = new StringBuilder();
                for (int j = 0;j < i + 1;++j){
                    sb.append(i);
                    sb.append(' ');
                    for (int k = 0;k < i;++k){
                        sb.append(res[j][k] + 1);
                        if(k + 1 != i)sb.append(' ');
                        else sb.append('\n');
                    }
                }
                System.out.println(sb);
                return;
            }
        }
        System.out.println("No");
    }




}
