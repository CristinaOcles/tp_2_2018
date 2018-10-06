#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000



typedef struct
{
    int id;
    char name[20];
    char lastName[20];
    float salary;
    int idSector;
    int isEmpty;

} eEmployee;






int initEmployees(eEmployee list[], int len);
int getFreeSpace(eEmployee list[],int len);
int addEmployee(eEmployee list[],int len, int id, char name[],char lastName[],float salary,int sector);
int enterEmployee (eEmployee list[],int len);
int newEmployee (eEmployee list[],int len);
int findEmployeeById(eEmployee list[],int len, int id);
int menuSectores();
int removeEmployee(eEmployee list[], int len, int id);
int removeForId(eEmployee list[], int len);
void printEmployee(eEmployee oneEmployee);
void printEmployees(eEmployee list[], int len);
int modifyEmploye(eEmployee list[], int len);
void modifyName(eEmployee list[], int len, int index);
void modifyLastName(eEmployee list[], int len, int index);
void modifySalary(eEmployee list[], int len, int index);
void modifySector(eEmployee list[], int len, int index);






int main()
{

    char seguir='s';
    int opcion=0;
    int idEmployee = 1000;


    eEmployee employees[TAM];
    initEmployees(employees, TAM);




    while(seguir=='s')
    {
        printf("\n");
        printf("1- Alta de personas\n");
        printf("2- Modificar datos de persona\n");
        printf("3- dar de baja a una persona\n");
        printf("4- informar\n\n");
        printf("5- Salir\n");



        printf("\n");
        do
        {
            printf("Ingrese opcion\n");
            scanf("%d",&opcion);
            printf("\n");

        }
        while ( opcion < 1 || opcion > 5 );


        switch(opcion)
        {
        case 1:
            newEmployee(employees, TAM);
            system("pause");
            system("cls");
            break;
        case 2:

            modifyEmploye(employees, TAM);
            system("pause");
            system("cls");

            break;
        case 3:
            removeForId(employees, TAM);
            system("pause");
            system("cls");
            break;
        case 4:

            system("pause");
            system("cls");
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }






    return 0;
}











int initEmployees(eEmployee list[], int len)
{
    int retorno = -1;

    if(list != NULL && len > 0)


        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        }
    retorno = 0;


    return retorno;
}


int getFreeSpace(eEmployee list[],int len)
{

    int index = -1;

    for (int i=0; i<len; i++)
    {
        if (list[i].isEmpty==1)
        {
            index = i;
            break;
        }
    }
    return index;
}





int addEmployee(eEmployee list[],int len, int id, char name[],char lastName[],float salary,int sector)
{
    int retorno = -1;
    int index;

    index = id - 1;

    if (list!=NULL && len>0)
    {

        strcpy (list[index].name,name);
        strcpy (list[index].lastName,lastName);
        list[index].id = id;
        list[index].salary = salary;
        list[index].idSector = sector;
        list[index].isEmpty=0;

        retorno = 0;
    }



    return retorno;

}




int newEmployee (eEmployee list[],int len)
{
    int id;
    char name[20];
    char lastName[20];
    float salary;
    int idSector;
    int index;
    int existeId;
    int opcion;
    int retorno;

    system("cls");
    index = getFreeSpace(list,len);

    if( index == -1)
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }

    if (list!=NULL && len>0 && index>=0)
    {

        printf("\n ***alta de empleados*** \n");

        id = index + 1;
        existeId = findEmployeeById(list, len, id);

        if(existeId>-1)
        {
            printf("Ingrese nombre: \n");
            fflush(stdin);
            gets(name);
            printf("Ingrese Apellido: \n");
            fflush(stdin);
            gets(lastName);
            printf("Ingrese salario: \n");
            fflush(stdin);
            scanf("%f", &salary);
            printf("Ingrese sector");
            idSector = menuSectores();
            printf("\n\n");

            printf("Nombre       apellido       salario      sector\n\n");
            printf("%10s %10s %5.2f  %10d\n\n", name, lastName, salary, idSector);
            printf("Si los datos son correctos ingrese 1, si los datos son incorrectos ingrese 9\n");
            scanf("%d", &opcion);

            if(opcion == 1)
            {
                retorno = addEmployee(list,len,id,name,lastName,salary,idSector);

                if(retorno == 0)
                {
                    printf("Alta exitosa!!!!\n\n");
                    retorno = 0;
                }
                else
                {
                    printf("Alta sin efecto: \n");
                    retorno = -1;
                }

            }
            else
            {
                printf("Alta cancelada: \n");
                retorno = -1;
            }



        } else{

            printf("Ya existe un empleado con el id %d\n", id);
            printEmployee(list[index]);
            system("pause");
        }



        return retorno;

    }



}


int findEmployeeById(eEmployee list[],int len, int id)
{
    int index;

    if(list!=NULL && len>0 && id >-1)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == id && list[i].isEmpty == 0);
            {index = i;
            break;
            }
        }

    }

    return index;
}



int menuSectores()
{

    int opcion;


    printf(" Lista de sectores\n");
    printf(" solo ingresar numeros\n\n");

    printf(" 1- RRHH\n");
    printf(" 2- SISTEMAS\n");
    printf(" 3- LIMPIEZA\n");


    printf("\n\n");
    do
    {
        printf("Ingrese opcion (1/2/3) \n");
        scanf("%d",&opcion);
        printf("\n");

    }
    while ( opcion < 1 || opcion > 3 );

    return opcion;
}





int removeEmployee(eEmployee list[], int len, int id)
{
    int retorno = -1;
    int index;
    index = id - 1;

    if(list[index].id  == id)
    {
        list[index].isEmpty = 1;
        retorno = 0;
    }

    return retorno;

}


int removeForId(eEmployee list[], int len)
{

    int id;
    int existe;
    int baja;
    char seguir;

    printf("\n ***Baja de empleado***\n\n");

    printf("Ingrese Id de empleado: \n");
    scanf("%d", &id);

    existe = findEmployeeById(list, len, id);

    if(existe>-1)
    {
         printEmployee(list[existe]);

            printf("\nDesea eliminar? s/n: \n");
            fflush(stdin);
            scanf("%c", &seguir);

            if(seguir == 'n')
            {
                printf("Baja cancelada\n");
            }
            else{
            baja = removeEmployee(list, len, id);
            printf("Baja exitosa! \n");

            }
    }
    else
    {
        printf("El id ingresado no corresponde a un empleado\n\n");
    }

    return 0;

}




void printEmployee(eEmployee oneEmployee)
{
    int index;

    char sectores[3][10] = {"RRHH", "SISTEMAS", "LIMPIEZA"};

    index = oneEmployee.idSector - 1;

    printf("%3d   %6s     %6s     %5.2f     %10s\n\n", oneEmployee.id, oneEmployee.name, oneEmployee.lastName, oneEmployee.salary, sectores[index]);

}



void printEmployees(eEmployee list[], int len)
{
    system("cls");

    printf("\n  id     nombre      apellido      salario     sector\n\n");

    for (int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            printEmployee(list[i]);
        }
    }


    system("pause");


}


int modifyEmploye(eEmployee list[], int len)
{
    int id;
    int indice;
    int empleado;
    int opcion;
    int retorno = -1;


    printf("Modificar empleado \n\n");

    printEmployees(list, len);

    printf("Ingrese id de empleado\n");
    scanf("%d", &id);

    while (id<1 && id>1000)
    {
        printf("El id ingresado no es correcto\n");
        printf("Ingrese id de empleado\n");
        scanf("%d", &id);
    }

    indice = findEmployeeById(list, len, id);

    if(indice>-1)
    {
        indice = id - 1;

        printEmployee(list[indice]);
        printf("\n\nElija la opcion a modificar\n\n");
        printf("1- modificar nombre\n");
        printf("2- Modificar apellido\n");
        printf("3- modificar salario\n");
        printf("4- modificar sector\n");


        do
        {
            printf("Ingrese opcion (1/2/3/4) \n");
            scanf("%d",&opcion);
            printf("\n");

        }
        while ( opcion < 1 || opcion > 3 );


        switch(opcion)
        {
        case 1:
            modifyName(list, len, indice);
            break;
        case 2:
            modifyLastName(list, len, indice);
            break;
        case 3:
            modifySalary(list, len, indice);
            break;
        case 4:
            modifySector(list, len, indice);
            break;
        default:
            break;
        retorno = 0;
        }
    }else{
                printf("No se encuentra ningun empleado con ese id\n");
                retorno = -1;

        }




}












void modifyName(eEmployee list[], int len, int index)
{
        char seguir;
        char newName[20];


        printf("\nModifica nombre? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo nombre: ");
            scanf("%s", newName);
            strcpy(list[index].name,newName);

            printf("Modificacion exitosa\n\n");
        }
}



void modifyLastName(eEmployee list[], int len, int index)
{

        char seguir;
        char newLastName[20];


        printf("\nModifica Apellido? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo apellido: ");
            scanf("%s", newLastName);
            strcpy(list[index].lastName, newLastName);

            printf("Modificacion exitosa\n\n");
        }
}





void modifySalary(eEmployee list[], int len, int index)
{
        char seguir;
        float newSalary;

        printf("\nModifica salario? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo salario: ");
            scanf("%f", &newSalary);
            list[index].salary = newSalary;

            printf("Modificacion exitosa\n\n");
        }
}





void modifySector(eEmployee list[], int len, int index)
{

        char seguir;
        int newSector;

        printf("\nModifica sector? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo sector: ");
            newSector = menuSectores();

            scanf("%d", &newSector);
            list[index].idSector = newSector;

            printf("Modificacion exitosa\n\n");
        }


}


