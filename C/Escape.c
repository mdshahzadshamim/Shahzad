#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int body(int);
int main()
{
	system("cls");
	
	int p,con;
	double i,pi,j,pj,vk,v,r;
	double m,gcon,g;
	char bod[10];
	gcon = 6.67430e-11;
	
	printf("For Sun or other planets of our Solar System, press 0 to 8.\n");
	printf("For other celestial bodies press 9 . . . ");
	scanf("%d",&p);
	
	if(p == 0)
	{
		r = 696340;
		m = 1.9884e30;
	}
	else if(p == 1)
	{
		r = 2439.7;
		m = 3.3011e23;
	}
	else if(p == 2)
	{
		r = 6051.8;
		m = 4.8675e24;
	}
	else if(p == 3)
	{
		r = 6371.0;
		m = 5.97237e24;
	}
	else if(p == 4)
	{
		r = 3389.5;
		m = 6.4171e23;
	}
	else if(p == 5)
	{
		r = 69911;
		m = 1.8972e27;
	}
	else if(p == 6)
	{
		r = 58232;
		m = 5.6834e26;
	}
	else if(p == 7)
	{
		r = 25362;
		m = 8.6810e25;
	}
	else if(p == 8)
	{
		r = 24622;
		m = 1.02413e26;
	}
	else if(p == 9)
	{
		printf("Celestial Body : ");
		scanf("%s",bod);
		
		printf("Radius(in kms) = ");
		scanf("%lf",&r);
		
		printf("Mass(in kgs) = ");
		scanf("%lf",&m);
	}
	
	/*if(p >= 0 && p<9)body(p); else if(p == 9) printf("%s",bod);*/
	
	printf("To calculate escape velocity, press 0 . . . ");
	scanf("%d",&con);
	if(con == 0)
	{
		printf("Enter the launch distance from "); if(p >= 0 && p<9) body(p); else if(p == 9) printf("%s",bod); printf("'s surface(in kms) : ",bod);
		scanf("%lf",&i);
		pj = 0;
	}
	else
	{
		printf("Enter the launch distance from "); if(p >= 0 && p<9) body(p); else if(p == 9) printf("%s",bod); printf("'s surface(in kms) : ");
		scanf("%lf",&i);
		
		printf("Enter the destination distance from "); if(p >= 0 && p<9) body(p); else if(p == 9) printf("%s",bod); printf("'s surface(in kms) : ");
		scanf("%lf",&j);
		
		pj = (1 /((j + r) * 1000));
	}
	
	pi = (1 / ((i + r) * 1000));
	vk = sqrt(2 * gcon * m * (pi - pj));
	
	/* 2*gcon*m = 790735520000000 */
	
	v = vk / 1000;
	g = gcon * m /(r * r * 1000000);
	if( con == 0)
	{
		if(i == 0)
		{
			printf("The escape velocity from "); if(p >= 0 && p<9) body(p); else if(p == 9) printf("%s",bod); printf("'s surface is %lf km/s.\n",v);
		}
		else
		{
			printf("The escape velocity from %lf kms from ",i); if(p >= 0 && p<9) body(p); else if(p == 9) printf("%s",bod); printf("'s surface is %lf km/s.\n",v);
		}
	}
	else
	{
		printf("Velocity required from %lf kms from the surface of ",i); if(p >= 0 && p<9) body(p); else if(p == 9) printf("%s",bod); printf(" to go %lf kms is %lf km/s.\n",j,v);
	}
	
	printf("The gravitational fiel(g) here is %lf m/s^2.\n",g);
	
	return 0;
}

int body(int i)
{
	if(i == 0)
	printf("Sun");
	
	else if(i == 1)
	printf("Mercury");
	
	else if(i == 2)
	printf("Venus");
	
	else if(i == 3)
	printf("Earth");
	
	else if(i == 4)
	printf("Mars");
	
	else if(i == 5)
	printf("Jupiter");
	
	else if(i == 6)
	printf("Saturn");
	
	else if(i == 7)
	printf("Uranus");
	
	else if(i == 8)
	printf("Neptune");
}