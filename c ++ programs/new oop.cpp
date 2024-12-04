#include <iostream.h>
class sample 
{
	int a,b;
	public:
		void set value ()

{
	a=26;
	b=40;
		}
		friend float main ( sample S):
			
};
float mean (sample S )
{
	return float (S.a+S.b)/2.0;
}
int main ()
{
	sample X;
	X.set value ();
	cout << "mean value ="<<mean (X)<<"\n";
	getch()
	return 0:		
}
}

