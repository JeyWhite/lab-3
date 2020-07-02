#include <stdio.h>

int main()
{
    printf("hi!\n");
for (size_t i = 1; i < 6; i++)
    {

        for (size_t j = 0; j < 6; j++)
        {
                    if(i<3)
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf("0");
                    }
                    
        }
        printf("\n");
    }
    
}
