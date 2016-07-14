import java.io.*;
class logic
{
	void cal_prime(double num)
	{
		double i;
		for( i=2;i<num;i++)
		{
			if(num%i==0)
			{
				System.out.println("The given number is prime");
				break;
			}
		}
		if(i>=num)
		{
			
			System.out.println("The given number is not prime");
		}
	}
}
class primeno
{
	public static void main(String args[])throws IOException
	{
		logic ob=new logic();
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter a number for checking");
		double num=Double.parseDouble(in.readLine());
		ob.cal_prime(num);
	}
}
