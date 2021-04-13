#include "stdio.h"
#include "stdlib.h"

void files_fgetc()
{
    FILE* fp = fopen("f1.txt", "r");

    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    };

    // ici le curseur est sur la fin du fichier EOF
    c = 'a';
    long pos = ftell(fp);
    c = fgetc(fp);  // on voit que c donne toujours EOF
    pos = ftell(fp);  // la position ne change plus

    fclose(fp);
}

void read_fgets()
{
    FILE* fp = fopen("f1.txt", "r");
    long int p = ftell(fp);
    char txt[30];
    char* c = fgets(txt, 29, fp);  // 1ere ligne
    p = ftell(fp);
    c = fgets(txt, 29, fp);  // 2ème ligne
    p = ftell(fp);
    c = fgets(txt, 29, fp);  // c == NULL car tout est lu
    p = ftell(fp);  // la position ne change pas
    fclose(fp);
}

#define SMALL_BUFF 5
void read_fgets_small_buff()
{
    FILE* fp = fopen("f1.txt", "r");
    long int p = ftell(fp);
    char txt[SMALL_BUFF];

    char* c = fgets(txt, SMALL_BUFF, fp);  // txt == Hell
    c = fgets(txt, SMALL_BUFF, fp);  // o\n  Attention fgets s'arrête sur le \n
    c = fgets(txt, SMALL_BUFF, fp);  // foo
    fclose(fp);
}

void files_fscanf()
{
    FILE* fp = fopen("meas.txt", "r");
    int i1, i2;

    int ret = fscanf(fp, "%d,%d", &i1, &i2);
    ret = fscanf(fp, "%d,%d", &i1, &i2);
    ret = fscanf(fp, "%d,%d", &i1, &i2);  // ret = 0 car il y a une lettre au début de la ligne
    ret = fscanf(fp, "%d,%d", &i1, &i2);  // idem, toujours 0 tant que la lettre n'est pas lue

    char c1;
    ret = fscanf(fp, "%c,%d", &c1, &i2);
    ret = fscanf(fp, "%c,%d", &c1, &i2);  // ret == -1 car c'est la fin du fichier
    fclose(fp);

    // lecture par boucle
    fp = fopen("meas.txt", "r");
    if( fp == NULL )
        exit(EXIT_FAILURE);

    int tab[20];
    int pos = 0;
    do
    {
        ret = fscanf(fp, "%d,%d", &tab[pos], &tab[pos+1]);
        pos++;
        if( ret != 2){
            break;
            //exit(EXIT_FAILURE);
        }

    } while (ret != EOF);

    fclose(fp);
}

void write_putc()
{
    FILE* fp = fopen("putc.txt", "w");
    fputc('a', fp);
    fputc('b', fp);
    fputs("cd", fp);  // la ligne est écrite sans le \n

    fprintf(fp, "\n\nMes valeurs : %-8d%10.2lf\n", 12345, 4.56);
    fprintf(fp, "Mes valeurs : %-8d%10.2lf", 87, 781.3);
    fclose(fp);
}

void exemple_fseek()
{
    FILE* f = fopen("fseek.txt", "r");
    long pos = ftell(f);
    fseek(f, 0, SEEK_SET);
    fseek(f, 4, SEEK_SET);
    pos = ftell(f);
    char c = fgetc(f);
    fseek(f, 2, SEEK_CUR);
    c = fgetc(f);
    fseek(f, 5, SEEK_CUR);
    pos = ftell(f);
    c = fgetc(f);
    fclose(f);
}


void fichier_binaire()
{
    fprintf(stdout, "Test lecture fichier binaire\n");

    // Pas de lecture car le pointeur est au bout
    FILE* fp = fopen("bin1.dat", "w+");
    int buffer_out[] = {1, 2, 3, 4, 5, 6};
    int buffer_in[6] = {0};

    fwrite(buffer_out, sizeof(int), 6, fp);

    long pos = ftell(fp);
    printf("Position : %ld\n", pos);

    fseek(fp, 0, SEEK_SET);

    pos = ftell(fp);
    printf("Position : %ld\n", pos);

    fread(buffer_in, sizeof(int), 6, fp);

    for (int i = 0; i < 4; i++) printf("Val %d : %d\n", i, buffer_in[i]);

    fclose(fp);
}

void fichier_binaire_char()
{
    FILE* fp = fopen("bin_c1.dat", "w");
    char buffer_out[] = {'1', '2', '3', 123};
    fwrite(buffer_out, sizeof(char), 4, fp);
    fclose(fp);

    fp = fopen("bin.txt", "w");
    fprintf(fp, "12345");
    fclose(fp);
}


void create_files()
{
    // Création des fichiers de test
    FILE* f = fopen("f1.txt", "w");
    fputs("Hello\nfoo", f);
    fclose(f);

    f = fopen("meas.txt", "w");
    fputs("1,2\n3,4\nA,8", f);
    fclose(f);

    FILE* fp = fopen("fseek.txt", "w");
    fputs("ABCD\nEFGH", fp);
    fclose(fp);
}

void create_meas_tab_fixe()
{
    FILE* f = fopen("meas_tab_fixe.txt", "w");
    const int size = 6;  // largeur peut changer chaque colonne
    fprintf(f, "%*s%*s%*s%*s\n", size, "num", size, "val1", size, "val2", size,
            "val3");  // on écrit l'entête

    fprintf(f, "%*d%*d%*d%*d\n", size, 1, size, 10, size, 20, size, 30);
    fprintf(f, "%*d%*d%*d%*d\n", size, 2, size, -45, size, 1234, size, -456);
    fclose(f);
}

void read_meas_tab_fixe()
{
    int line = 2;
    int val;
    FILE* f = fopen("meas_tab_fixe.txt", "r");
    fseek(f, line * (6 + 6 + 6 + 6 + 1), SEEK_SET);
    fseek(f, 6 + 6, SEEK_CUR);
    fscanf(f, "%d", &val);
    printf("Int lu : %d\n", val);
    fclose(f);
}


struct Data {
    int i;
    double d;
    char c;
};


void exemple_struct(){
    struct Data s1 = { .i=10, .d=3.45, .c='t' };    
    struct Data s2 = { .i=20, .d=6.45, .c='z' };

    // Save
    FILE* f = fopen("ex_struct.txt1", "w+");

    // solutions point par point
    //fwrite(&s1.i, sizeof(int), 1, f);
    //fwrite(&s1.d, sizeof(double), 1, f);
    //fwrite(&s1.c, sizeof(char), 1, f);

    fwrite(&s1, sizeof(struct Data), 1, f);
    //fwrite(&s2, sizeof(struct Data), 1, f);

    fseek(f, 0, SEEK_SET);

    // Read
    struct Data s_r1, s_r2;
    fread(&s_r1, sizeof(struct Data), 1, f);
    //fread(&s_r2, sizeof(struct Data), 1, f);

    fprintf(stdout, "i=%d d=%.2lf c=%c\n", s_r1.i, s_r1.d, s_r1.c);
}

void fichier()
{
    create_files();
    files_fgetc();
    read_fgets();
    read_fgets_small_buff();
    files_fscanf();
    write_putc();
    exemple_fseek();

    create_meas_tab_fixe();
    read_meas_tab_fixe();

    fichier_binaire();

    fichier_binaire_char();

    exemple_struct();
}