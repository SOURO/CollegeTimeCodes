class x
{
        x f()
        {
                return new x();
        }
}
class y extends x
{
        y f()
        {
                return new y();
        }
}
class covarient
{
        public static void main(String args[])
        {
                x ob=new y();
                y ob1=ob.f();

       }
}
