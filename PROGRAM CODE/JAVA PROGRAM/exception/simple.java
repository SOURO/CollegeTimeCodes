class simple
{
        public static void main(String args[])
        {
	int a=0;
	int b;
	for(int i=0;i<=1;i++)
	{
		
		try
		{
                 		 	b=43/a;
		}
		catch(ArithmeticException e)
		{
			System.out.println("arithmetic exception:"+e);
			//a=1;
		}
                 		System.out.println("next statement after catch is also executed");
		//System.out.println("b=" +b);
	}
        }
}
                
                
