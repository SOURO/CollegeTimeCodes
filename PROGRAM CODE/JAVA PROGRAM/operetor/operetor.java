class Operetion
{
	long addition(String a1,String a2)
	{
		long s=Integer.parseInt(a1) + Integer.parseInt(a2);
		return s;
	}
	long substraction(String s1,String s2)
	{
		long s=Integer.parseInt(s1) - Integer.parseInt(s2);
		return s;
	}
	long multiplication(String m1,String m2)
	{
		long s=Integer.parseInt(m1) * Integer.parseInt(m2);
		return s;
	}
	long division(String d1,String d2)
	{
		long s=Integer.parseInt(d1) / Integer.parseInt(d2);
		return s;
	}
	long modulation(String m3,String m4)
	{
		long s=Integer.parseInt(m3) % Integer.parseInt(m4);
		return s;
	}
}
		
class Operetor
{ 
	public static void main(String args[])
	{
		Operetion o=new Operetion();
		 if(args.length!=3)
		{
			System.out.println();
			System.out.println("FOLLOW THIS FORMAT::operend1 arithmatic_operetor operend2");
			System.exit(0);
		}
		else
		{
			long s1=0;
			switch(args[1].charAt(0))
			{
				
				case '+':
					s1=o.addition(args[0],args[2]);
					break;
				case '-':
					s1=o.substraction(args[0],args[2]);
					break;
				case '*':
					s1=o.multiplication(args[0],args[2]);
					break;
				case '/':
					s1=o.division(args[0],args[2]);
					break;
				case '%':
					s1=o.modulation(args[0],args[2]);
					break;
				default:
					System.out.println();
					System.out.println("FOLLOW THIS FORMAT::operend1 arithmatic_operetor operend2");
					System.exit(0);
			}
			System.out.println();
			System.out.println(args[0]+' '+args[1]+' '+args[2]+" = "+ s1);
		}
	}
}		
	
				