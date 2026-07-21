import javax.swing.text.TabableView;
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int minCost=Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        InputReader in=new InputReader(System.in);
        int n=in.nextInt();
        long k=in.nextLong()+1;
        int []aim=new int[n];
        for(int i=0;i<n;i++) aim[i]=in.nextInt();
        List<Integer> list=new ArrayList<>();
        int cur=1;
        int len=-1;
        int start=-1;
        list.add(1);
        boolean []visit=new boolean[n+1];
        visit[1]=true;
        while (true){
            int next=aim[cur-1];
            if(!visit[next])
                list.add(next);
            else{
                int i=0;
                for(i=0;i<list.size();i++)
                    if(list.get(i)==next)
                        break;
                len=list.size()-i;
                start=i;
                break;
            }
            visit[next]=true;
            cur=next;
        }
        if(k<list.size())
            out.println(list.get((int)(k-1) ));
        else{
            long  cha = k-list.size();
            int yu= (int) (cha%len);
            if(yu==0) out.println(list.get(list.size()-1));
            else out.println(list.get(start+yu-1));
        }
        out.flush();
    }
    static class InputReader{
        private BufferedReader in;
        private StringTokenizer tokenizer;
        public InputReader(InputStream stream){
            in = new BufferedReader(new InputStreamReader(stream),32768);
            tokenizer = null;
        }
        public String next() throws IOException{
            while(tokenizer==null || !tokenizer.hasMoreTokens()){
                tokenizer = new StringTokenizer(in.readLine());
            }
            return tokenizer.nextToken();
        }
        public Long nextLong() throws IOException {
            String next = next();
            return Long.valueOf(next);
        }
        public int nextInt() throws IOException{
            return Integer.valueOf(next());
        }
    }
}
