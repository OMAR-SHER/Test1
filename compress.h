#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

struct cArray {
    int character;
    char word[15];
};

class compressor {
    struct cArray dictionary[100];
    int count = 0;
public:
    unsigned char compress(char s[])
    {

        if (!exists(s))
        {
            return  assignChar(s);
        }
        return find(s);
        //create 2d array of with %c and num1
    }

    unsigned char assignChar(char word[])
    {
        dictionary[count].character = count + 130;
        strcpy(dictionary[count].word, word);
        count = count + 1;
        //decompress('0'+count-1+128);
        return (count - 1) + 130;
    }

    bool exists(char word[])
    {
        for (int i = 0; i < count; i++)
        {
            if (strcmp(dictionary[i].word, word) == 0)
            {
                return true;
            }
        }
        return false;
    }

    int find(char word[])
    {
        for (int i = 0; i < count; i++)
        {
            if (strcmp(dictionary[i].word, word) == 0)
            {
                return dictionary[i].character;
            }
        }
        return -1;
    }


    char* decompress(unsigned char compressedChar)
    {

        for (int i = 0; i < count; i++)
        {
            //char str[i] = (char)((num % 26) - 48);
            if (compressedChar == dictionary[i].character)
            {
                return dictionary[i].word;
            }
        }
        return (char*)compressedChar;
    }

    char* concat(unsigned char word, char* temp) {

        unsigned char c = word;
        int i = 0;
        for (i = 0; temp[i] != '\0'; i++)
        {

        }
        if (i == 0)
        {
            temp[i] = c;
            temp[i + 1] = '\0';
        }
        else {
            temp[i - 1] = c;
            temp[i] = '\0';
        }
        return temp;
    }

    void startComp()
    {
        FILE* out_file;
        char out_name[] = "compressed.txt";
        out_file = fopen(out_name, "w");
        char word[50];
        unsigned char a;
        char temp[50] = "";
        FILE* obj = openFile();
        if (obj != NULL)
        {
            while (fscanf(obj, "%s", word) != EOF)
            {
                printf("%s\n", word);
                printf("\n%c", compress(word));
                printf("\ncheck1");
                a = compress(word);
                strcpy(temp, concat(a, temp));
                //strcat(temp,(char*)compress(word));
                strcat(temp, " ");
                //fprintf(out_file, " ");
                printf("\ncheck3");
            }
        }
        else
        {
            return;
        }
        fprintf(out_file, "%s", temp);
        printf("%s", temp);
        fclose(out_file);
        //delete temp;
    }
    FILE* openFile()
    {
        FILE* in_file;
        char in_name[80];
        printf("Enter file name:\n");
        scanf("%s", in_name);
        strcat(in_name, ".txt");
        // use appropriate location if you are using MacOS or Linux
        in_file = fopen(in_name, "r");
        if (in_file == NULL)
        {
            printf("\nFile is not available!\n");
            //exit(1);
            return NULL;
        }
        else
        {
            return in_file;
        }
    }

   
        void startDecompress()
        {
            //
            FILE* out_file;
            char out_name[] = "decompress.txt";
            out_file = fopen(out_name, "w");
            //
            char temp[150];
            FILE* in_file;
            unsigned char word = ' ';
            in_file = fopen("compressed.txt", "r");
            if (in_file == NULL)
            {
                printf("\nCompressed file is not available!\n");
            }
            else
            {
                while (fscanf(in_file, "%c", &word) != )//!= EOF
                {
                    //printf("%c\n", word);
                    word;//only for debugging
                  
                    
                    //size_t destination_size = sizeof(decompress(word));

                   // strncpy(temp, decompress(word), destination_size);
                    //temp[destination_size - 1] = '\0';
                   //******************************
                    //printf("\n%s", decompress(temp));
                    //
                    //strcat(temp, decompress(word));
                    memcpy(temp, decompress(word), sizeof(decompress(word)));
                    printf("\n%s", temp);
                    //strcat(temp, " ");
                    fprintf(out_file, "%s", temp);
                   // printf("\n%s", decompress(word));
                    printf("\ncheck1");


                }
            }
            //fprintf(out_file, "%s", temp);
            fclose(out_file);

        }
        
        /*
            void convert(int unique)
            {
                int indx=(unique==0)?1:log10(unique)+1;
                printf("\nCheck1");
                printf("\n%d", unique);
                int str[10];

                printf("\n %s", str);

                int num = 0;

                char abc[indx];
                sprintf(abc,"%d",unique);
                int n = strlen(abc);


                for (int i = 0; i < n; i++)
                {
                    str[i] = ((abc[i] % 10) + 0);//number creator

                    printf("\nThis is %c",str[i]);
                };
                printf("\n%s", str);
                //printf("\nThis is %s", str);
            }*/

};