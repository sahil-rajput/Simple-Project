/*                  SAHIL RAJPUT                         */
/*C program which do funtion of "ls" command in Linux
 i.e : print all files in directory and sub-directories.*/
#include <stdio.h>
#include <dirent.h>

int main(int argc , char* argv[])
{
    if(argc > 2)
    {
        printf("\nERROR : Usage : %s <Direcotry Path>\n", argv[0]);
        return -1;
    }
    struct dirent *dir_entry;
    DIR *dir = opendir(argv[1]);
    if (dir == NULL)
    {
        printf("\nERROR : Not able to open current directory.\n" );
        return -1;
    }
    while ((dir_entry = readdir(dir)) != NULL)
    {
        printf("%s\n", dir_entry->d_name);
    }
    closedir(dir);
    return 0;
}
