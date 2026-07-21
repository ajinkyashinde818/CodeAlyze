import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner stdIn=new Scanner(System.in);

        int K=stdIn.nextInt(); //1周の距離
        int N=stdIn.nextInt(); //家の軒数
        
        int min=0;
        int []a=new int[N];

        for(int i=0; i<N; i++){
            a[i]=stdIn.nextInt();
        }

        for(int i=0; i<N-1; i++){
            if(a[i+1]-a[i]>min){
                min=a[i+1]-a[i];
            }
        }
        if(K-a[N-1]+a[0]>min){
            min=K-a[N-1]+a[0];
        }
        System.out.println(K-min);
        

        
    }

}
