class star
{
	int i;
	star(int i)
	{
		this.i=i;
	}
	void show()
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
class autostar
{
	public static void main(String args[])
	{
		star ob=new star(5);
		ob.show();
	}
}