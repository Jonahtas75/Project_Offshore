#include <stdio.h>
#include <stdlib.h>

int y = 0;
int x = 0;
int y_Toekomst;
int x_Toekomst;
int z = 100;

int locatie_Toekomst()
{
    printf("Op welke Y waarde komt de ton?\n");
    scanf("%d",&y_Toekomst);
    while(y_Toekomst > 100)
    {
    printf("De Y waarde moet onder de 100 liggen. Op welke Y waarde komt de ton?\n");
    scanf("%d",&y_Toekomst);
    }

    printf("Op welke X waarde komt de ton?\n");
    scanf("%d",&x_Toekomst);
    while(x_Toekomst > 100)
    {
    printf("De X waarde moet onder de 100 liggen. Op welke X waarde komt de ton?\n");
    scanf("%d",&x_Toekomst);
    }

    printf("Y_Toekomst = %d en X_Toekomst = %d\n",y_Toekomst,x_Toekomst);
}

int Z_transport()
{
    if(z == 100)
    {
        for(;z > 0;z--)
        {
            printf("Z = %d\n",z);
        }
    }
    else
    {

        for(;z < 100;z++)
        {
            printf("Z = %d\n",z);
        }
    }
}

int X_transport()
{
    if(x == 0)
    {
        for(;x < x_Toekomst; x++)
        {
            printf("X = %d\n",x);
        }
    }
    else
    {
        for(;x > 0;x--)
        {
            printf("X = %d\n",x);
        }
    }
}

int Y_transport()
{
if(y == 0)
    {
        for(;y < y_Toekomst; y++)
        {
            printf("Y = %d\n",y);
        }
    }
    else
    {
        for(;y > 0;y--)
        {
            printf("Y = %d\n",y);
        }
    }
}

magneet_Toggle()
{
    if(x == 0 && y == 0)
    {
        printf("Magneet gaat aan\n");
    }
    else
    {
        printf("Magneet gaat uit\n");
    }
}

int main()
{
    locatie_Toekomst();
    Z_transport();
    magneet_Toggle();
    Z_transport();
    X_transport();
    Y_transport();
    Z_transport();
    magneet_Toggle();
    Z_transport();
    Y_transport();
    X_transport();

    return 0;
}


