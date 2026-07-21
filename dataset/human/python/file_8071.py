import std.stdio, std.conv, std.string;

void main()
{
  int[] num = readln.chomp.split(' ').to!(int[]);
  int ret = 0;
  for(int X = 0; X <= num[0]; X++)
    {
      for(int Y = 0; Y <= num[0]; Y++)
	{
	  int remain = num[1] - (X + Y);
	  if(remain >= 0 && remain <= num[0])ret++;
	}
    }
  ret.writeln;
}
