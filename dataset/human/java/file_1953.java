using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int[] inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();

        int itemCount = inpt[0];

        this.Target = inpt[1];

        for (int i = 1; i <= itemCount; i++) {
            inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
            this.Haiten.Add(i * 100, inpt[0]);
            this.Complete.Add(i * 100, inpt[1]);
        }
        this.KeyList = this.Haiten.Keys.OrderByDescending(a => a).ToArray();

        int ans = GetAns(0, this.Target);
        Console.WriteLine(ans);
    }

    private int Target;

    private Dictionary<int, int> Complete = new Dictionary<int, int>();
    private Dictionary<int, int> Haiten = new Dictionary<int, int>();


    private int GetAns(int idx, int remain) {
        if(remain <= 0) {
            return 0;
        }
        if(idx >= this.KeyList.Length) {
            return -1;
        }
        if(!dic.ContainsKey(idx)) {
            dic.Add(idx, new Dictionary<int, int>());
        }
        if(dic[idx].ContainsKey(remain)) {
            return dic[idx][remain];
        }

        int ans = int.MaxValue;
        int unit = KeyList[idx];

        for (int i = 0; i < Haiten[unit]; i++) {
            int tmp = GetAns(idx + 1, remain - (unit * i));
            if(tmp < 0) {
                continue;
            }
            tmp += i;
            ans = Math.Min(ans, tmp);
        }
        int t2 = GetAns(idx + 1, remain - (unit * Haiten[unit] + Complete[unit]));
        if(t2 >= 0) {
            t2 += Haiten[unit];
            ans = Math.Min(ans, t2);
        }
        if(ans == int.MaxValue) {
            ans = -1;
        }
        dic[idx][remain] = ans;
        return ans;
    }

    private int[] KeyList;
    private Dictionary<int, Dictionary<int, int>> dic = new Dictionary<int, Dictionary<int, int>>();

    public class Reader
    {
        static StringReader sr;
        public static bool IsDebug = false;
        public static string ReadLine()
        {
            if (IsDebug)
            {
                if (sr == null)
                {
                    sr = new StringReader(InputText.Trim());
                }
                return sr.ReadLine();
            }
            else
            {
                return Console.ReadLine();
            }
        }
        private static string InputText = @"




5 25000
20 1000
40 1000
50 1000
30 1000
1 1000


";
    }

    public static void Main(string[] args)
    {
#if DEBUG
        Reader.IsDebug = true;
#endif
        Program prg = new Program();
        prg.Proc();
    }
}
