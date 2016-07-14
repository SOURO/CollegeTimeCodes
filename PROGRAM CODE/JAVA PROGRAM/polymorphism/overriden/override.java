class a
{
        void print()
        {
                System.out.println("sourabrata");
        }
}
class b extends a
{
        void print()
        {
	super.print();
                System.out.println("mukherjee");
        }
}
class override
{
        public static void main(String args[])
        {
                a ob=new a();
                b ob1=new b();
                ob.print();
                ob1.print();
        }
}
        
