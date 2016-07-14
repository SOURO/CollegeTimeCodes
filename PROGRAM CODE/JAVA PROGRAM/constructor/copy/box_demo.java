class Box
{
	double height,depth,length;
	double box_vol()
	{
		return height * depth * length;
	}
	void show(double v)
	{
		System.out.println("Volume of box is="+v);
	}
	
	Box(double l,double h,double d)
	{
		System.out.println();
		System.out.println("Constructing Box1");
		height=h;
		depth=d;
		length=l;
	}
	Box(Box b)
	{
		System.out.println();
		System.out.println("Constructing Box2");
		height=b.height;
		depth=b.depth;
		length=b.length;
	}
}
class Box_demo
{
	public static void main(String args[])
	{
		Box b1=new Box(30.5,12.0,20.2);
		double v1=b1.box_vol();
		b1.show(v1);
		Box b2=new Box(b1);
		double v2=b2.box_vol();
		b2.show(v2);
	}
}	
		