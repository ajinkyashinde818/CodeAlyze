import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        int n = in.nextInt();
        int m = in.nextInt();
        String []a = new String[n];
        String []b = new String[m];
        for (int i = 0;i<n;i++){
            a[i] = in.next();
        }
        for (int i = 0;i<m;i++){
            b[i] = in.next();
        }
        Boolean pass=true;
        for(int i=0;i<n-m+1;i++){
            for(int j=0;j<n-m+1;j++){
                pass=true;
                for(int k =0;k<m;k++){
                    if(!pass)
                        break;
                    for(int l=0;l<m;l++){
                        if(a[i+k].charAt(j+l)!=b[k].charAt(l)){
                            pass=false;
                            break;
                        }
                    }

                }
                if(pass){
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");

    }
}
