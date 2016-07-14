class logic
{
	double num1,num2,i,hcf=1,lcm;
	logic(int n1,int n2)
	{
		num1=n1;
		num2=n2;
	}
	double cal_hcf()
	{
		if(num1<num2)
		{
			if(num2%num1==0)
			{
				return num1;

			}
			else
			{
				for(i=2;i<num1;i++)
				{
					while(num1%i==0&&num2%i==0)

					{
						hcf=hcf*i;
						num1=num1/i;
						num2=num2/i;
					}
				}
				return hcf;	
			}
		}
		else
		{
			if(num1%num2==0)
			{
				return num2;

			}
			else
			{
				for(i=2;i<num2;i++)
				{
					while(num1%i==0&&num2%i==0)

					{
						hcf=hcf*i;
						num1=num1/i;
						num2=num2/i;
					}
				}
				return hcf;	
			}
		}
	}
	double cal_lcm()
	{
		lcm=hcf*num1*num2;
		return lcm;
	}
	void show(double h,double l)
	{
		System.out.println("THE HCF  VALUE OF THIS TWO NUMBER IS "+h);
		System.out.println("THE LCM  VALUE OF THIS TWO NUMBER IS "+l);
	}
}


class hcflcm
{
	public static void main(String args[])
	{
		logic ob=new logic(7,5);
		double h=ob.cal_hcf();
		double l=ob.cal_lcm();
		ob.show(h,l);
	}
}
		