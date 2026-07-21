import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        String line1=s.nextLine();
        String line2=s.nextLine();
        String[] SNum1=line1.split(" ");
        String[] SNum2=line2.split(" ");
        int town=Integer.parseInt(SNum1[0]);
        long step=Long.valueOf(SNum1[1]);
        int[] A=new int[town];
        for(int i=0;i<town;i++){
            A[i]=Integer.parseInt(SNum2[i]);
        }

        int[] B=new int[town];
        int[] C=new int[town];

        int counter=0;
        int currentTown=0;
        int loopNum=0;
        int startTown;
        while (true){
            B[currentTown]++;
            if(B[currentTown]==2){
                startTown=currentTown;
                loopNum=counter-C[currentTown];
                break;
            }
            C[currentTown]=counter;
            counter++;
            currentTown=A[currentTown]-1;
        }

        if(step>counter){
            step=(step-counter)%loopNum;
            currentTown=startTown;
        }else if(step>C[currentTown]){
            step=step-C[currentTown];
            currentTown=startTown;
        }else{
            currentTown=0;
        }

        for(int i=0;i<step;i++){
            currentTown=A[currentTown]-1;
        }
        System.out.println(currentTown+1);

    }
}
