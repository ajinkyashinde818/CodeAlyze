import std.functional,
       std.algorithm,
       std.container,
       std.typetuple,
       std.typecons,
       std.bigint,
       std.string,
       std.traits,
       std.array,
       std.range,
       std.stdio,
       std.conv,
       std.format,
       std.math;

void main()
{
	auto ip = readln.chomp;
	if(ip[0] == ip[2]) writeln("=");
	else if(ip[0] < ip[2]) writeln("<");
	else writeln(">");
}
