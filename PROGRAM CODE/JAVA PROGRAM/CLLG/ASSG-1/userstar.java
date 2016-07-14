import java.io.*;
class star
{
	void show(int i)
	{
		for(int k=0;k<i;k++)
		{
			for(int j=0;j<=k;j++)
			{
				System.out.print("*");
			}
			System.out.print("\n");
		}
	}
}
class userstar
{
	public static void main(String args[]) throws IOException
	{
		int i;
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the no. of step of this pattern");
		i=Integer.parseInt(in.readLine());
		star ob=new star();
		ob.show(i);
	}
}