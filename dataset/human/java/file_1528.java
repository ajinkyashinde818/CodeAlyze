import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int N = Integer.parseInt(sc.next());
        int M = Integer.parseInt(sc.next());
        
        String[][] img = new String[N][N];
        for(int i=0; i<N; i++){
            String[] a = sc.next().split("");
            for(int j=0; j<N; j++){
                img[i][j] = a[j];
            }
        }
        
        String[][] tmp_B = new String[M][M];
        for(int i=0; i<M; i++){
            String[] a = sc.next().split("");
            for(int j=0; j<M; j++){
                tmp_B[i][j] = a[j];
            }
        }
        
        for(int y=0; y<N; y++){
            for(int x=0; x<N; x++){
                int count = 0;
                for(int i=0; i<M; i++){
                    for(int j=0; j<M; j++){
                        if(y+i<N  && x+j <N){
                            if(img[y+i][x+j].equals(tmp_B[i][j])){
                                count++;
                            }
                        }
                    }
                }
                
                if(count == M*M){
                    System.out.println("Yes");
                    return;
                }
            }
        }
        
        System.out.println("No");
    }
}
