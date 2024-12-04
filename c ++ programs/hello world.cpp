# include <iostream.h>
#include<conio.h>
void line();
int main()
{

clrscr();
line();
cout<<"\n HELLO WORLD \n";
line();
getch();
return0;
}
void line ()
{
	for ( int i=0; i<=25 ; i++)
	{
		cout<<"-";
	}
}
