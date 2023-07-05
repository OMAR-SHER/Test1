#include"Header.h"

int main()
{
    compressor obj;
    int opt = 0;
    while (opt != 3)
    {
        printf("\nSelect the Options ");
        printf("\n1) Compressed file  ");
        printf("\n2) Decompress file  ");
        printf("\n3) Exit  \n");
        scanf("%d", &opt);
        if (opt == 1)
        {
            obj.startComp();
        }
        else if (opt == 2)
        {
             obj.startDecompress();
        }
        else
        {
            printf("\nSelect the available options\n");
        }
    }
}