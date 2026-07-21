import java.util.Scanner;

public class Main {

    public Main() {
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
int N=scan.nextInt();
int u1=0;
        int u2=0;
        int u3=0;

for(int i=0;i<N;i++) {
    int a = scan.nextInt();
    int b = scan.nextInt();
    if (a == b && u1 == 1 && u2 == 1) {
        u3 = 1; }
    else if(a == b && u1 == 1) {u2=1;
    }
else if(a == b){u1=1;}
if(a!=b){u1=0;
u2=0;
}
}
if(u3==1){System.out.println("Yes");}

else{System.out.println("No");}
    }
}
