/*
    Before running this code please make sure that
you have created a folder named "Hospital"
in 'c' drive,Create another folder named
"FileNameGuide" inside Hospital folder
(if they don't exist).

    If you want any changes in directories/folders
where the details should be saved,make alterations
accordingy in the gobal variabes('dir' and 'folder')
declared in the code(line number 18).
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
char static c;
char static dir[]="//storage//emulated//0//Hospital//",folder[]="FileNameGuide//AllFileNames";
char static name[]="Name",id[]="Id",gender[]="Gender",bed_no[]="Bed number",bill[]="Bill",doa[]="Date of Admission",dod[]="Date of Discharge",col=':';
struct pat
  {
    char name[100],id[100],gender[10],doa[100],dod[100],bed_no[100],bill[100];
   };
void add();
void edit();
void del();
void view();
void file_names();
void heading(char decor,char matter[]);
void file_name_generate(char *file_name,char *reference);
int main()
{
    int choise;
beginning:    
    heading('%',"Patient Details Management Portal");
    printf("Enter 1 to add new patient details\nEnter 2 to edit patient details\nEnter 3 to delete patient details\nEnter 4 to view patient details\nEnter 5 to view patients' file name\nEnter 6 to exit\n\n");    
    scanf("%d",&choise);  
    switch(choise)
      {
        case 1:add();
               break;
        case 2:edit();
               break;
        case 3:del();
               break;
        case 4:view();
               break;
        case 5:file_names();
               break;
        case 6:exit(0);
       default:printf("Enter a valid choise\n");
                break;
      }
    goto beginning;
  }
void heading (char decor,char matter[])
{
    int i;
    clrscr();
for(i=1;i<=72;i++)
    printf("%c",decor);
    printf("\n");
printf("\t\t%s\n",matter);
    for(i=1;i<=72;i++)
    printf("%c",decor);
    printf("\n\n");
}
void file_name_generate(char*file_name,char *reference)
{
    strcpy(file_name,dir);
    strcat(file_name,reference);
    strcat(file_name,".txt");
}
void add()
  {
    struct pat np;
    char temp,fn[100],a[]="File Name(Id)";
    FILE *fp;
    int i;
    heading('+',"\tNew Patient Details");
    printf("Enter specified details\n\n");
    printf("Name   :      ");
    getchar();
    scanf("%[^\n]s",np.name);
    printf("Id     :      ");
    getchar();
    scanf("%[^\n]s",np.id);
 gender:   printf("Gender :[m/f] ");
    getchar();
    scanf("%c",&temp);
    if(temp=='m'||temp=='M'){
        strcpy(np.gender,"Male");
    }
    else if(temp=='f'||temp=='F')
        {
        strcpy(np.gender,"Female");
         }
    else 
        {
        printf("Enter m or f\n");
        goto gender;
        }
    printf("Bed no :      ");
    getchar();
    scanf("%[^\n]s",np.bed_no);
    printf("Bill   :      ");
    getchar();
    scanf("%[^\n]",np.bill);
    printf("D O A  :      ");
    getchar();
    scanf("%[^\n]s",np.doa);
    printf("D O D  :      ");
    getchar();
    scanf("%[^\n]s",np.dod);
    file_name_generate(fn,np.id);
    fp=fopen(fn,"w");
    fprintf(fp,"%-25s%-5c%s\n%-25s%-5c%s\n%-25s%-5c%s\n%-25s%-5c%s\n%-25s%-5c%s\n%-25s%-5c%s\n%-25s%-5c%s\n",name,col,np.name,id,col,np.id,gender,col, np.gender,bed_no,col,np.bed_no,bill,col,np.bill,doa,col,np.doa,dod,col,np.dod);
    fclose(fp);
    file_name_generate(fn,folder);
    fp=fopen(fn,"r");
    if(fp==NULL)
    {
        fp=fopen(fn,"w");
        for(i=1;i<=60;i++)
        fprintf(fp,"-");
        fprintf(fp,"\n");
        fprintf(fp,"%-30s%s\n",name,a);
        for(i=1;i<=60;i++)
        fprintf(fp,"-");
        fprintf(fp,"\n\n");
    }
    fclose(fp);
    fp=fopen(fn,"a");
    fprintf(fp,"%-30.25s%s\n",np.name,np.id);
    fclose(fp);
    printf("\nSuccessfully saved\n\n");  
    getchar();
    printf("Press Enter to continue");
    getchar();
  }
void edit()
{
    FILE *fp,*t_fp;
    int ch,op,i,no_of_lines=0;
    struct pat ep,np;
    char fn[100],file_name[100],e_fn[100],n_fn[100],
con,temp,o_line[100],t_line[100],t_fn[100],t_file[]="temp";
    heading('~',"\tPatient's Details Modification");
    printf("Enter filename(id) of the patient\t");
    getchar();
    scanf("%[^\n]s",file_name);
    file_name_generate(fn,file_name);
    fp=fopen(fn,"r");
    printf("\n");
    if(fp==NULL)
    {
        printf("The file does not exist\n\n");
        goto end;
    }
    else
    {
      printf("Current Details\n\n"); 
      while((ch=fgetc(fp))!=EOF)
        {
          printf("%c",ch);
        }
           fclose(fp);
           printf("\n");
        }
    fp=fopen(fn,"r");
    for(i=0;i<30;i++)
    fgetc(fp);
    fscanf(fp,"%[^\n]s",ep.name);
    for(i=0;i<31;i++)
    fgetc(fp);
    fscanf(fp,"%[^\n]s",ep.id);
    for(i=0;i<31;i++)
    fgetc(fp);
    fscanf(fp,"%[^\n]s",ep.gender);
    for(i=0;i<31;i++)
    fgetc(fp);
    fscanf(fp,"%[^\n]s",ep.bed_no);
    for(i=0;i<31;i++)
    fgetc(fp);
    fscanf(fp,"%[^\n]s",ep.bill);
    for(i=0;i<31;i++)
    fgetc(fp);
    fscanf(fp,"%[^\n]s",ep.doa);
    for(i=0;i<31;i++)
    fgetc(fp);
    fscanf(fp,"%[^\n]s",ep.dod);
    fclose(fp);
    strcpy(np.name,ep.name);
    strcpy(np.id,ep.id);
    strcpy(np.gender,ep.gender);
    strcpy(np.bed_no,ep.bed_no);
    strcpy(np.bill,ep.bill);
    strcpy(np.doa,ep.doa);
    strcpy(np.dod,ep.dod);
start:
    printf("Enter 1 to modify Name\nEnter 2 to modify Id\nEnter 3 to modify Gender\nEnter 4 to modify Bed number\nEnter 5 to modify Bill\nEnter 6 to modify D O A\nEnter 7 to modify D O D\nEnter 8 to Return\n\n");    
    scanf("%d",&op);
    switch(op)   
   {
        case 1:printf("Enter new Name : ");
               getchar();
               scanf("%[^\n]s",np.name);
               break;
        case 2:printf("Enter new Id : ");
               getchar();
               scanf("%[^\n]s",np.id);
               break;
        case 3:do
            {
            getchar();
        printf("Change Gender?[y/n] : ");
            scanf("%c",&temp);
            if(temp=='y'||temp=='Y')
            {
                 if(strcmp(ep.gender,"Male")==0)
                {
                    strcpy(np.gender,"Female");
                }
                else
                {
                    strcpy(np.gender,"Male");
                }
                break;
            }
            else if(temp=='n'||temp=='N')
            {
                break;
            }
            else
            {
                printf("Enter a valid choise\n");
            }
            }while(1);
               break;
        case 4:printf("Enter new Bed number : ");
               getchar();
               scanf("%[^\n]s",np.bed_no);
               break;
        case 5:printf("Enter new Bill amount : ");
               getchar();
               scanf("%[^\n]s",np.bill);
               break;
        case 6:printf("Enter new D O A : "); 
               getchar();
               scanf("%[^\n]s",np.doa);
               break;
        case 7:printf("Enter new D O D : ");
               getchar();
               scanf("%[^\n]s",np.dod);
               break;
        case 8:do
            {
                  getchar();
            printf("Save changes?[y/n] : ");
                  scanf("%c",&con);
            printf("\n");
                  if(con=='y'||con=='Y')
                  {
                   if(strcmp(ep.id,np.id)!=0)
                    {
                    file_name_generate(e_fn,ep.id);
                    file_name_generate(n_fn,np.id);
                     rename(e_fn,n_fn);
                     }
                file_name_generate(fn,np.id);
    fp=fopen(fn,"w");
    fprintf(fp,"%-25s%-5c%s\n%-25s%-5c%s\n%-25s%-5c%s\n%-25s%-5c%s\n%-25s%-5c%s\n%-25s%-5c%s\n%-25s%-5c%s\n",name,col,np.name,id,col,np.id,gender,col, np.gender,bed_no,col,np.bed_no,bill,col,np.bill,doa,col,np.doa,dod,col,np.dod);
    fclose(fp);
                if(strcmp(ep.name,np.name)!=0||strcmp(ep.id,np.id)!=0)
                {
                    file_name_generate(fn,folder);
                    file_name_generate(t_fn,t_file);
                    t_fp=fopen(t_fn,"w");
                    fprintf(t_fp,"%-30.25s%s\n",ep.name,ep.id);
                    fclose(t_fp);
                    t_fp=fopen(t_fn,"r");
                    fscanf(t_fp,"%[^\n]s",o_line);
                    fclose(t_fp);
                    t_fp=fopen(t_fn,"w");
                    fp=fopen(fn,"r");
                    while((ch=fgetc(fp))!=EOF)
                    {
                        if(ch=='\n')
                        no_of_lines++;
                    }
                    rewind(fp);
                    for(i=0;i<no_of_lines;i++)
                    {
                        strcpy(t_line," ");
                        fscanf(fp,"%[^\n]s",t_line);
                        fgetc(fp);
                        if(strcmp(o_line,t_line)==0)
                        {
                            fprintf(t_fp,"%-30.25s%s\n",np.name,np.id);
                        }
                        else
                        {
                            fprintf(t_fp,"%s\n",t_line);
                        }
                    }
                    fclose(fp);
                    fclose(t_fp);
                    fp=fopen(fn,"w");
                    t_fp=fopen(t_fn,"r");
                    while((ch=fgetc(t_fp))!=EOF)
                    {
                        fputc(ch,fp);
                    }
                    fclose(fp);
                    fclose(t_fp);
                    remove(t_fn);
                }
                      printf("Details updated successfully\n\n");
                      break;
                    } 
             else if(con=='n'||con=='N')
                    {
                      printf("Modifications denied\n\n");
                      break;
                    }
             else
                 {
                  printf("Enter a valid choise\n");
                 }
            }while(1);
            goto end;
       default:printf("Enter a valid choise\n");
                break;
    }
    printf("\n");
    goto start;
end:
    getchar();
    printf("Press Enter to continue\n");
    getchar();
}
void del()
{
    struct pat ep;
    FILE *fp,*t_fp;
    int ch,i,no_of_lines=0;
    char fn[100],file_name[100],op,t_fn[100],t_file[]="temp",o_line[100],t_line[100];
    heading('-',"\tDelete Patient Details");
    printf("Enter the File name(Id) of the patient : ");
    getchar();
    scanf("%[^\n]s",file_name);
    file_name_generate(fn,file_name);
    fp=fopen(fn,"r");
    printf("\n");
    if(fp==NULL)
    {
        printf("The file does not exist\n\n");
        goto end;
    }
    else
    {
        do
        {
            getchar();
            printf("Do you want to proceed?[y/n] : ");
            scanf("%c",&op);
            if(op=='y'||op=='Y')
      {
                fp=fopen(fn,"r");
    for(i=0;i<30;i++)
    fgetc(fp);
    fscanf(fp,"%[^\n]s",ep.name);
    for(i=0;i<31;i++)
    fgetc(fp);
    fscanf(fp,"%[^\n]s",ep.id);
    fclose(fp);
               if(remove(fn)==0)
    {
                    file_name_generate(fn,folder);
                    file_name_generate(t_fn,t_file);
                    t_fp=fopen(t_fn,"w");
                    fprintf(t_fp,"%-30.25s%s\n",ep.name,ep.id);
                    fclose(t_fp);
                    t_fp=fopen(t_fn,"r");
                    fscanf(t_fp,"%[^\n]s",o_line);
                    fclose(t_fp);
                    t_fp=fopen(t_fn,"w");
                    fp=fopen(fn,"r");
                    while((ch=fgetc(fp))!=EOF)
                    {
                        if(ch=='\n')
                        no_of_lines++;
                    }
                    rewind(fp);
                    for(i=0;i<no_of_lines;i++)
                    {
                        strcpy(t_line," ");
                        fscanf(fp,"%[^\n]s",t_line);
                        fgetc(fp);
                        if(strcmp(o_line,t_line)==0)
                        {
                            continue;
                        }
                        else
                        {
                            fprintf(t_fp,"%s\n",t_line);
                        }
                    }
                    fclose(fp);
                    fclose(t_fp);
                    fp=fopen(fn,"w");
                    t_fp=fopen(t_fn,"r");
                    while((ch=fgetc(t_fp))!=EOF)
                    {
                        fputc(ch,fp);
                    }
                    fclose(fp);
                    fclose(t_fp);
                    remove(t_fn);
        printf("\nFile has been deleted successfully\n\n");
    }
    else
    {
        printf("\nError! Unable to Delete the file\n\n");
       }
                break;
      }
         else if(op=='n'||op=='N')   
            {
                printf("\nFile not deleted\n\n");
                break;
            }
       else
            {
                printf("Enter a valid choise\n");
            }  
        }while(1);
}    
 end:
    getchar();
    printf("Press Enter to continue\n");
    getchar();
}
void view()
{
    FILE *fp;
    int ch;
    char fn[100],file_name[100];
    heading('=',"\tExisting Patient Details");
    printf("Enter filename(id) of the patient\t");
    getchar();
    scanf("%[^\n]s",file_name);
    file_name_generate(fn,file_name);
    fp=fopen(fn,"r");
    printf("\n");
    if(fp==NULL)
    {
        printf("The file does not exist\n\n");
    }
    else
    {
    while((ch=fgetc(fp))!=EOF)
        {
          printf("%c",ch);
        }
           fclose(fp);
           printf("\n");
        }
    getchar();
    printf("Press Enter to continue\n");
    getchar();
}
void file_names()
{
    FILE *fp;
    int ch;
    char fn[100];
    heading('*',"\tPatients' File Names");
    file_name_generate(fn,folder);
    fp=fopen(fn,"r");
    if(fp==NULL)
    {
        printf("No details yet\n\n");      
    }
    else
    {
    while((ch=fgetc(fp))!=EOF)
        {
          printf("%c",ch);
        }
    fclose(fp);
        }
    getchar();
    printf("Press Enter to continue\n");
    getchar();
}