import org.omg.Messaging.SYNC_WITH_TRANSPORT;
import org.omg.PortableServer.LIFESPAN_POLICY_ID;
import sun.nio.cs.ext.MacHebrew;

import javax.management.StringValueExp;
import java.math.BigDecimal;
import java.nio.ByteBuffer;
import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        int count = 0;
        boolean sw = false;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        double dMax = Double.MIN_VALUE;
        double dMin = Double.MAX_VALUE;
        //
        Scanner sc = new Scanner(System.in);
        //int n = sc.nextInt();
        long a = sc.nextLong();
        long b = sc.nextLong();
        Compute c = new Compute();
        long ans = (a*b)/c.gcd(a,b);
        System.out.println(ans);


        sc.close();
    }

    public class Pair<F,S>
    {
        private final F first;
        private final S second;

        Pair(F first,S second)
        {
            this.first = first;
            this.second = second;
        }

        public void print() { System.out.println("("+this.first+","+this.second+")"); }

        //get
        public F first() {return this.first;}
        public S second() {return this.second;}

        @Override
        public boolean equals(Object object)
        {
            if (object instanceof Pair)
            {
                Pair pair = (Pair)object;
                return this.first==pair.first && this.second==pair.second;
            }else
            {
                return false;
            }
        }

        @Override
        public int hashCode()
        {
            return Objects.hash(first,second);
        }
    }
}

class BIT
{
    int []bit;
    int n;
    public BIT(int n) {
        this.n = n;
        bit = new int[n + 1];
    }
    int sum(int i) {
        int sum = 0;
        while(i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }
    void add(int i, int x) {
        while(i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
}

class Compute
{
    int combination(int n,int r)//nCrの組み合わせの解(int)
    {
        int denominator = 1;//分母
        int molecule = 1;//分子

        int e1 = 1;
        int e2 = 1;
        for (int i=1;i<=r;++i)
        {
            e1 *= i;
        }
        for (int i=1;i<=(n-r);++i)
        {
            e2 *= i;
        }
        denominator = e1*e2;

        for (int i=1;i<=n;++i)
        {
            molecule *= i;
        }

        return molecule/denominator;
    }

    long combination(long n,long r)//nCrの組み合わせの解(long)
    {
        long denominator = 1;//分母
        long molecule = 1;//分子

        long e1 = 1;
        long e2 = 1;
        for (long i=1;i<=r;++i)
        {
            e1 *= i;
        }
        for (long i=1;i<=(n-r);++i)
        {
            e2 *= i;
        }
        denominator = e1*e2;

        for (long i=1;i<=n;++i)
        {
            molecule *= i;
        }

        return molecule/denominator;
    }

    int cumulativeSum(int A[],int k)//kの大きさごとに配列Aを切り取ってその区間内の数を足した時の最大値をreturn
    {
        int ans=0;
        //累積和表を作成
        int B[]=new int[A.length+1];//累積和に使う配列
        B[0]=0;
        for(int i=1;i<B.length;i++)
        {
            B[i]=B[i-1]+A[i-1];
        }

        //最大値を求める
        int tmp=0;
        ans=B[k]-B[0];
        for(int i=1;i<A.length-k;i++)
        {
            tmp=B[i+k]-B[i];
            if(tmp>ans)
            {
                ans=tmp;
            }
        }
        System.out.println(Arrays.toString(B));
        return ans;
    }

    public int gcd(int x,int y)//ユークリッドの互除法を使って2値の最大公約数を求める(int)
    {
        int tmp;
        if(x<y)
        {
            tmp=x;
            x=y;
            y=tmp;
        }
        if(x==0)//(x or y)=0の時は0でない時の値を返す
        {
            return y;
        }else if(y==0)
        {
            return x;
        }else
        {
            while ((tmp = x % y) != 0)
            {
                x = y;
                y = tmp;
            }
            return y;
        }
    }

    public static long gcd(long x,long y)//ユークリッドの互除法を使って2値の最大公約数を求める(long)
    {
        long tmp;
        if(x<y)
        {
            tmp=x;
            x=y;
            y=tmp;
        }
        if(x==0)//(x or y)=0の時は0でない時の値を返す
        {
            return y;
        }else if(y==0)
        {
            return x;
        }else
        {
            while ((tmp = x % y) != 0)
            {
                x = y;
                y = tmp;
            }
            return y;
        }
    }

    public int leastCommonMultiple(int a,int b)//最大公倍数(int)
    {
        int ans=1;
        //ans=(a*b)/gcd(a,b);//(2値a,bの最小公倍数は ab/(aとbの最大公約数) で求められる) <- だけどオーバフローする可能性があるので下の処理で
        ans=a/gcd(a,b)*b;
        return ans;
    }

    public long leastCommonMultiple(long a,long b)////最大公倍数(long)
    {
        long ans=1;
        //ans=(a*b)/gcd(a,b);//(2値a,bの最小公倍数は ab/(aとbの最大公約数) で求められる)
        ans=a*gcd(a,b)*b;
        return ans;
    }

    public List<Integer> divisors(int n)//ある数の約数を列挙した配列を返す(int)
    {
        List<Integer> list =new ArrayList<>();
        for (int i=1;i*i <= n; ++i)
        {
            if (n%i !=0) continue;
            list.add(i);
            if (n/i == i) continue;
            list.add(n/i);
        }

        return list;
    }

    public List<Long> divisors(long n)//ある数の約数を列挙した配列を返す(long)
    {
        List<Long> list =new ArrayList<>();
        for (long i=1;i*i <= n; ++i)
        {
            if (n%i !=0) continue;
            list.add(i);
            if (n/i == i) continue;
            list.add(n/i);
        }
        return list;
    }

    public boolean isPrime(int n)//素数かどうかを判定する(int)
    {
        if (n==1) return false;//1は素数でない

        for (int i=2;i*i<=n; ++i)//2以上sqrt(n)以下に約数がある時，nは約数とは言えない
        {
            if (n%i == 0) return false;
        }
        return true;
    }

    public boolean isPrime(long n)//素数かどうかを判定する(long)
    {
        if (n==1) return false;//1は素数でない

        for (long i=2;i*i<=n; ++i)//2以上sqrt(n)以下に約数がある時，nは約数とは言えない
        {
            if (n%i == 0) return false;
        }
        return true;
    }

    public Map<Integer,Integer> primeFactors(int n)//素因数分解(int)//key=素数 value=乗数のmapを返す
    {
        Map <Integer,Integer> map = new HashMap<>();

        if (n==1)
        {
            map.put(n,1);
            return map;
        }

        int nn=n;
        for (int i=2;i*i<=n;++i)
        {
            while (n%i ==0)
            {
                if (map.get(i) == null)
                {
                    map.put(i,1);
                    n/=i;
                }else
                {
                    int t=map.get(i)+1;
                    map.put(i,t);
                    n/=i;
                }
            }
        }

        if (n!=1) map.put(n,1);

        return map;
    }

    public Map<Long,Long> primeFactors(long n)//素因数分解(int)//key=素数 value=乗数のmapを返す
    {
        Map <Long,Long> map = new HashMap<>();
        long t1=1;

        if (n==1)
        {
            map.put(n,t1);
            return map;
        }

        long nn=n;
        for (long i=2;i*i<=n;++i)
        {
            while (n%i ==0)
            {
                if (map.get(i) == null)
                {
                    map.put(i,t1);
                    n/=i;
                }else
                {
                    long t=map.get(i)+1;
                    map.put(i,t);
                    n/=i;
                }
            }
        }

        if (n!=1) map.put(n,t1);

        return map;
    }

    //SieveOfEratosthenes
    public int numOfSieveOfEratosthenes(int n)//エラトステネスの篩//このコードでは素数の数を出す//n以下の素数の数
    {
        //ここに入っている値が1なら,indの値は素数
        //なので，素数を列挙したかったら，下の処理が終わった後にvalueが1のindを出せば良い
        int primeList[]=new int[n+1];

        for (int i=0;i<n+1;++i)
        {
            if (i==0 || i==1) primeList[i]=0;//0と1は素数ではない
            else primeList[i] = 1;//とりあえず全部に1をおく
        }

        int count=0;
        for (int i=0;i<n+1;++i)
        {
            if (primeList[i]==1)
            {
                ++count;
                //iが素数判定した値
                for (int j=i+i;j<=n;j+=i)//素数と判定した場合，nまでその数を足し上げていき，その数を素数出ないと判定する
                {
                    primeList[j]=0;
                }
            }
        }
        return count;
    }
}
