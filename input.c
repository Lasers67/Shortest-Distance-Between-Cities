#include<stdio.h>
#include<assert.h>
#include<limits.h>
#include<stdlib.h>
void main()
{
int x,y,source,target,ch;
int no_of_cities=0;
float w;
char b;
do{

	printf("Choose one of the following options-\n1.Enter distances between cities yourself.\n2.Take input from file. :");
	scanf("%d",&ch);
	switch(ch)	
	{
		case 1:{ printf("enter no. of cities.\n");
		scanf("%d",&no_of_cities);
		float dist_btw_cities[no_of_cities][no_of_cities];
		for(x=0;x<no_of_cities;x++)
		{
			for(y=x;y<no_of_cities;y++)
				{					
					if(y!=x)
					{   do{
							printf("Is city %d connected to city %d? : Y/N: " ,x+1,y+1);
							scanf(" %c",&b);

							if(b=='Y' || b=='y')
							{
								printf("enter the weight of the path btw nodes %d and %d:",x+1,y+1);
								scanf("%f",&w);
								dist_btw_cities[x][y]=dist_btw_cities[y][x]=w;
							}
							else if(b=='N' || b=='n')
								dist_btw_cities[x][y]=dist_btw_cities[y][x]=INT_MAX;
                	    	}while(b!='Y' && b!='y' && b!='N' && b!='n' );
					}
					else
						dist_btw_cities[x][y]=0;
				printf("\n");
				}
		}
		printf("the input matrix listing distances btw cities is:\n");
			for(x=-1;x<no_of_cities;x++)
			{
				for(y=-1;y<no_of_cities;y++)
					{
						if(x==-1&&y==-1)
							printf("w(u,v)\t");
						else if(x==-1&&y!=-1)
							{printf("city %d\t",y+1);}
						if(y==-1&&x!=-1)
							printf("city %d\t",x+1);
						else if(x!=-1&&y!=-1)
							{
								if(dist_btw_cities[x][y]==INT_MAX)
									printf("INF\t");
								else
									printf("%.2f\t",dist_btw_cities[x][y]);
							}
					}
				printf("\n");

			}
		}
   			break;
   		case 2: {
   				FILE *fin;
    	    	fin = fopen("input_file.txt","r");

		        char c;
        		while((c = fgetc(fin)) != EOF)
        		{		
                	if(c=='\n')
                    	no_of_cities++;
        		}
		        float dist_btw_cities[no_of_cities][no_of_cities];
        		fclose(fin);
        		fin = fopen("input_file.txt","r");

 		        x=0;y=0;
       			while(fscanf(fin, "%f ",&w) == 1)
       			{
       				dist_btw_cities[x][y]=w;
                	y++;
                	if(y==no_of_cities)
               		{
                    	y=0;
                    	x++;
                	}
        		}

				printf("the input matrix listing distances btw cities is:\n");
				for(x=-1;x<no_of_cities;x++)
				{
					for(y=-1;y<no_of_cities;y++)
					{
						if(x==-1&&y==-1)
							printf("w(u,v)\t");
						else if(x==-1&&y!=-1)
							{printf("city %d\t",y+1);}
						if(y==-1&&x!=-1)
							printf("city %d\t",x+1);
						else if(x!=-1&&y!=-1)
						{
							if(dist_btw_cities[x][y]==INT_MAX)
								printf("INF\t");
							else
								printf("%.2f\t",dist_btw_cities[x][y]);
						}
					}
				printf("\n");

			}
    	
	    }break;

	default: printf("\nWrong choice. Try again.\n\n");
		 break;

	}
}while(ch!=1 && ch!=2);
	printf("\nenter the source city: city ");
	scanf("%d",&source);
	printf("\nenter the target city: city ");
	scanf("%d",&target);

}
