import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine().trim();
        System.out.println(payment(s));
    }

    public static long payment(String s) {
        int[] client = new int[s.length()+1];
        int[] cashier = new int[s.length()+1];
        for (int i = 0; i < s.length(); i++) {
            client[i+1]=s.charAt(i)-'0';
        }
        for (int j = 0; j < 10; j++) {
            for (int i = client.length-1; i >0 ; i--) {
                //check if cachier can boost
                if(cashier[i]>0 && client[i]>0){
                    int min = Math.min(cashier[i], client[i]);
                    cashier[i]-=min;
                    client[i]-=min;
                }
                if(client[i]>=10){
                    client[i-1]+=client[i]/10;
                    client[i] = client[i]%10;
                }
                if(client[i]>5){
                    cashier[i]+=10-client[i];
                    client[i-1]+=1;
                    client[i]=0;
                }
                if(client[i]==5 && cashier[i-1]>0){
                    client[i]=0;
                    cashier[i-1]-=1;
                    cashier[i]+=5;
                }
                if(client[i]==5 && client[i-1]==5){
                    client[i-2]+=1;
                    client[i-1]=0;
                    client[i]=0;
                    cashier[i-1]+=4;
                    cashier[i]+=5;
                }
            }
        }

        long c = 0;
        for (int i = 0; i < client.length; i++) {
            c+=client[i]+cashier[i];
        }
        return c;
    }
}
