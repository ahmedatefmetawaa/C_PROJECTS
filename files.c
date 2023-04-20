#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[50], data[1000], choice;

    while (1)
    {
        printf("1. Create file\n");
        printf("2. Read file\n");
        printf("3. Update file\n");
        printf("4. Delete file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            printf("Enter the file name: ");
            scanf("%s", filename);
            fp = fopen(filename, "w");
            printf("Enter the data: ");
            scanf(" %[^\n]s", data);
            fprintf(fp, "%s", data);
            fclose(fp);
            printf("File created successfully.\n");
            break;
        case '2':
            printf("Enter the file name: ");
            scanf("%s", filename);
            fp = fopen(filename, "r");
            if (fp == NULL)
            {
                printf("File not found.\n");
                break;
            }
            printf("Data in file:\n");
            while (fgets(data, 1000, fp) != NULL)
            {
                printf("%s", data);
            }
            printf("\n");
            fclose(fp);
            break;
        case '3':
            printf("Enter the file name: ");
            scanf("%s", filename);
            fp = fopen(filename, "w");
            if (fp == NULL)
            {
                printf("File not found.\n");
                break;
            }
            printf("Enter the data: ");
            scanf(" %[^\n]s", data);
            fprintf(fp, "%s", data);
            fclose(fp);
            printf("File updated successfully.\n");
            break;
        case '4':
            printf("Enter the file name: ");
            scanf("%s", filename);
            if (remove(filename) == 0)
            {
                printf("File deleted successfully.\n");
            }
            else
            {
                printf("Unable to delete the file.\n");
            }
            break;
        case '5':
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}
