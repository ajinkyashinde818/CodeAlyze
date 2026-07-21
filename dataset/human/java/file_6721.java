import java.lang.reflect.Array;
import java.util.*;
import java.util.Map.*;
import java.io.*;
import java.util.StringTokenizer;
import java.util.Comparator;

public class Main {

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        Integer K = sc.nextInt();
        Integer N = sc.nextInt();
        Long[] As = sc.nextLongArray(N);
        long[] dist = new long [N];

        for(Integer i = 0; i < N; i++){
            Long right_loop = (long)0;
            Long left_loop = (long)0;
            if(i == 0)
                right_loop = As[N - 1] - As[i];
            else
                right_loop = K - (As[i] - As[i - 1]);

            if(i == N - 1)
                left_loop = As[N - 1];
            else
                left_loop = K - (As[i + 1] - As[i]);
            dist[i] = min(left_loop, right_loop);
        }


        System.out.println(Arrays.stream(dist).min().getAsLong());
    }

    public static boolean isPrime(long num){
        for(int i = 2; i < num;i++){
            if(num % i == 0)
                return false;
        }
        return true;
    }


    public static long factorial(Long n){
        if(n == 1)
            return 1;
        return n * factorial(n - 1);
    }

    public static <T> HashMap<T,Integer> count_item(T[] target){
        HashMap<T,Integer> hs = new HashMap<>();
        for(T t: target){
            if(hs.containsKey(t))
                hs.put(t,hs.get(t) + 1);
            else
                hs.put(t,1);
        }
        return hs;
    }

    public static class Iterations{

        // nCr を求める
        // 第1引数: 列挙対象の配列 n
        // 第2引数: r
        // 第3引数: 答えの組み合わせ配列を保持するための set
        public static <T> HashSet<ArrayList<T>> combination(ArrayList<T> n, Integer r) {
            HashSet<ArrayList<T>> ans = new HashSet<>();
            Iterations.comb(n,r,ans);
            return ans;
        }


        public static <T> void comb(ArrayList<T> n, Integer r, HashSet<ArrayList<T>> ans) {
            if (n.size() == r) {
                ans.add(n);
                return;
            }

            for (int i = 0; i < n.size(); i++) {
                ArrayList<T> N = new ArrayList<>(n);
                N.remove(i);
                comb(N, r, ans);
            }
        }


        // nPr を求める
        // 第1引数: 列挙対象の配列 n
        // 第2引数: r
        // 第3引数: 答えの組み合わせ配列を保持するための set
        public static <T> List<List<T>> permutation(T[] n,int r) {
            List<T> n_list = Arrays.asList(n);
            HashSet<ArrayList<T>> hs = combination(new ArrayList<>(n_list),r);

            List<List<T>> result = new ArrayList<>();
            for(ArrayList<T> tmp: hs){
                helper(0, tmp, result);
            }
            return result;
        }

        private static <T> void helper(int start, List<T> nums, List<List<T>> result) {
            if (start == nums.size() - 1) {
                ArrayList<T> list = new ArrayList<>();
                for (T num : nums) {
                    list.add(num);
                }
                result.add(list);
                return;
            }

            for (int i = start; i < nums.size(); i++) {
                swap(nums, i, start);
                helper(start + 1, nums, result);
                swap(nums, i, start);
            }
        }

        private static <T> void swap(List<T> nums, int i, int j) {
            T temp = nums.get(i);
            nums.set(i,nums.get(j));
            nums.set(j,temp);
        }
    }


    public static List<Entry<Integer,Integer>> SortMapByValue(HashMap<Integer,Integer> maps,boolean is_reverse){
        List<Entry<Integer,Integer>> entries = new ArrayList<>(maps.entrySet());

        Collections.sort(entries, new Comparator<Entry<Integer, Integer>>() {
            @Override
            public int compare(Entry<Integer, Integer> o1, Entry<Integer, Integer> o2) {
                return (is_reverse ? -1 : 1) * o1.getValue().compareTo(o2.getValue());
            }
        });

        return entries;
    }

    public static long max(int[] ar,int size){
        long max = 0;
        for(int i = 0; i< size;i++)
            if(max < ar[i])
                max = ar[i];
        return max;
    }

    public static <T extends Comparable<T>> T max(T left, T right){
        return left.compareTo(right) < 0 ? right : left;
    }

    public static <T extends Comparable<T>> T min(T left, T right){
        return left.compareTo(right) > 0 ? right : left;
    }

    public static long max(List<Long> ar){
        long max = 0;
        for(int i = 0; i< ar.size();i++)
            if(max < ar.get(i))
                max = ar.get(i);
        return max;
    }

    public static Integer min(List<Integer> ar){
        int min = 10000;
        int index = 0;
        for(int i = 0; i< ar.size();i++){
            if(min > ar.get(i)){
                min = ar.get(i);
                index = i;
            }
        }
        return min;
    }

    // 最大公約数を求める
    public static <T extends Number> Long gcd(T left, T right) {
        Long m = left.longValue();
        Long n = right.longValue();
        if(m == 0)
            return n;
        if(n == 0)
            return m;
        if(m < n) return gcd(n, m);
        if(n == 0) return m;
        return gcd(n, m % n);
    }

    // 最小公倍数を求める
    public static <T extends Number> Long lcm(T left, T right){
        return left.longValue() * right.longValue() / gcd(left,right);
    }

    // A 以上、B 以下のCの倍数の個数を考える (A <= B)
    public static <T extends Number> Long get_multiple_count(T A, T B,T C){
        Long b_multi = B.longValue() / C.longValue();
        Long a_multi = (A.longValue() - 1) / C.longValue();
        return b_multi - a_multi;
    }



    static class FastScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        public String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }

            return tokenizer.nextToken("\n");
        }

        public long nextLong() {
            return Long.valueOf(Long.parseLong(next()));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public String[] nextArray(int n) {
            String[] a = new String[n];
            for (int i = 0; i < n; i++)
                a[i] = next();
            return a;
        }


        public Long[] nextLongArray(int n) {
            Long[] a = new Long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }

    public static class SizeComparator implements Comparator<HashSet>{
        @Override
        public int compare(HashSet l1, HashSet l2){
            return l1.size() > l2.size() ? -1 : 1;
        }
    }
}
