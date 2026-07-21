import java.util.*;

class Main{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        List<String> s = new LinkedList<>();
        String[] s_tmp = sc.next().split("");
        for(int i=0;i<s_tmp.length;i++){
            s.add(s_tmp[i]);
        }
        Integer q = sc.nextInt();
        Integer rev = 0;
        for(int i=0;i<q;i++){
            Integer t = sc.nextInt();
            if(t==1){// 反転
                rev = (rev+1)%2;
            }
            else{// 追加
                Integer f = sc.nextInt();
                String c = sc.next();
                if(rev==1){//反転中
                    if(f==2){// 先頭にc
                        s.add(0, c);
                    }
                    else{// 末尾にc
                        s.add(c);
                    }
                }
                else{
                    if(f==1){// 先頭にc
                        s.add(0, c);
                    }
                    else{// 末尾にc
                        s.add(c);
                    }
                }
            }
        }

        if(rev==1){
            Collections.reverse(s);
        }
        for(String tmp : s){
            System.out.print(tmp);
        }

    }
}
