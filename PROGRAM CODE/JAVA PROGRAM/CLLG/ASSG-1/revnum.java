import  java.io.*;
class logic
{
	double reverse(double num)
	{
		double rev=0;
		while(num!=0)
		{
			double mod=num%10;
			 rev=rev*10+mod;
			num=num/10;
		}
          		return rev;
	}
}
class revnum
{
	public static void main(String args[])throws IOException
	{
		logic ob=new logic();
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter a number to reverse");
		double num=Double.parseDouble(in.readLine());
		double rev=ob.reverse(num);
		System.out.println("The reverse of the given no. is ="+rev);
	}
}
		

			