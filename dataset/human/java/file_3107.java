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
        this.IslandCount = inpt[0];
        int shipCount = inpt[1];
        for (int i = 0; i < shipCount; i++) {
            inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
            inpt.ToList().ForEach(a=>{
                if(!Ship.ContainsKey(a)) {
                    Ship.Add(a, new Dictionary<int, bool>());
                }
            });
            Ship[inpt[0]][inpt[1]] = true;
            Ship[inpt[1]][inpt[0]] = true;
        }
        string ans = "IMPOSSIBLE";
        if(CanReach(1, 2)) {
            ans = "POSSIBLE";
        }
        Console.WriteLine(ans);
    }

    private bool CanReach(int idx, int remain) {
        if(!this.Ship.ContainsKey(idx)) {
            return false;
        }
        if(remain == 0) {
            if(idx == IslandCount) {
                return true;
            }
            return false;
        }
        foreach(int next in Ship[idx].Keys) {
            if(next == 1) {
                continue;
            }
            if(CanReach(next, remain-1)) {
                return true;
            }
        }
        return false;
    }

    private int IslandCount = 0;
    private Dictionary<int, Dictionary<int, bool>> Ship = new Dictionary<int, Dictionary<int, bool>>();

    public class Reader
	{
		private static StringReader sr;
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

4 3
1 2
2 3
3 4


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
