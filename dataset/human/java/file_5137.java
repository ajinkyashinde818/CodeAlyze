import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String s = input.readLine();
        int q = Integer.parseInt(input.readLine());
        StringBuffer preSb = new StringBuffer();
        StringBuffer sb = new StringBuffer(s);
        boolean rvflag = false;

        for(int i=0;i<q;i++){
            String[] qn = input.readLine().split(" ");
            if(qn[0].equals("1")){
                rvflag = !rvflag;
            }else{
                if((qn[1].equals("1") && !rvflag) || (qn[1].equals("2") && rvflag)) {
                    preSb.append(qn[2]);
                }else if((qn[1].equals("2") && !rvflag) || (qn[1].equals("1") && rvflag)){
                    sb.append(qn[2]);
                }
            }
        }
        StringBuffer ans = new StringBuffer();
        ans.append(preSb.reverse());
        ans.append(sb);

        if(rvflag){
            ans.reverse();
        }
        System.out.println(ans.toString());
    }
}
