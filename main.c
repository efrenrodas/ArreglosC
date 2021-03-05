

#include<stdio.h>

#define ARREGLO_MAX 100

#define MAX_STRLEN 256



int main() {
	int c;
	int i;
	int j;
	int maximomes[12];
	int mayort;
	int mes;
	char *meses[12];
	int productomasvendido;
	char productos[MAX_STRLEN][ARREGLO_MAX];
	int s;
	int totalano;
	int totalmes[12];
	int totalmeses;
	int totalprod[ARREGLO_MAX];
	int v;
	int ventas[ARREGLO_MAX][12];
	/* definira el tamaño del arreglo para  crear la matriz */
	meses[0] = "Enero";
	meses[1] = "Febrero";
	meses[2] = "Marzo";
	meses[3] = "Abril";
	meses[4] = "Mayo";
	meses[5] = "Junio";
	meses[6] = "Julio";
	meses[7] = "Agosto";
	meses[8] = "Septiembre";
	meses[9] = "Octubre";
	meses[10] = "Noviembre";
	meses[11] = "Diciembre";
	c = 1;
	/* array de tipo cadena  */
	s = 1;
	mayort = 0;
	while (s>=1) {
    
		printf("Seleccione la opcion a realizar\n");
		printf("1 para llenar los productos\n");
		printf("2 para llenar las ventas\n");
		printf("3 para calculas las ventas anuales por productos\n");
		printf("4 Total de ventas de cada mes por producto\n");
		printf("5 para ver el procuto mas vendido por cada mes\n");
		printf("6 mostrar resultados\n");
		printf("7 mas vendido en el año\n");
		printf("0 para salir\n");
		scanf("%i",&s);
		switch (s) {
		case 1:
			printf("ingrese la cantidad de productos a crear\n");
			scanf("%i",&c);
			for (i=0;i<=c-1;i+=1) {
				printf("Ingrese el producto %i\n",i);
				scanf("%s",productos[i]);
			}
			break;
		case 2:
			/* array de tipo entero n filas y 12 columnas  */
			for (i=0;i<=c-1;i+=1) {
				for (j=0;j<=11;j+=1) {
					printf("Ingrese las ventas del producto %s para el mes %s\n",productos[i],meses[j]);
					scanf("%i",&ventas[i][j]);
				}
			}
			break;
		case 3:
			/* total de ventas anual de cada producto  */
			printf("Calculando las ventas anuales por producto....\n");
			for (i=0;i<=c-1;i+=1) {
				for (j=0;j<=11;j+=1) {
					/* Escribir "Sumando las ventas del producto",i," para el mes ",j; */
					totalano = ventas[i][j]+totalano;
				}
				totalprod[i] = totalano;
				totalano = 0;
			}
			break;
		case 4:
			/* total de ventas de cada uno de los meses de todos los productos  */
			printf("Calculando las ventas mensuales por producto....\n");
			for (i=0;i<=11;i+=1) {
				for (j=0;j<=c-1;j+=1) {
					/* Escribir "Sumando las ventas del producto",i," para el mes ",j; */
					totalmeses = ventas[j][i]+totalmeses;
				}
				totalmes[i] = totalmeses;
				totalmeses = 0;
			}
			break;
		case 5:
			/* almacena el numero del producto mas vendido en cada mes con ese codigo se puede buscar en los otros arreglos sobre nombre y cantidad */
			printf("Obtener codigo del mas vendido por mes en el año\n");
			for (i=0;i<=11;i+=1) {
				for (j=0;j<=c-1;j+=1) {
					/* Escribir "Comparando en el mes ",i," ",j; */
					/* ProductoMasVendido= Ventas[j,i]; */
					if (ventas[j][i]>=mayort) {
						mayort = ventas[j][i];
						productomasvendido = j;
					}
				}
				/* Escribir i; */
				/* Escribir MayorT," > ",ProductoMasVendido; */
				maximomes[i] = productomasvendido;
				productomasvendido = 0;
				mayort = 0;
			}
			/* escribir codigos de productos mas vendidos en el año por meses  */
			for (i=0;i<=11;i+=1) {
				printf("En el mes %i el codigo producto mas vendido es %s\n",i,productos[maximomes[i]]);
			}
			break;
		case 6:
			printf("Producto | E | F | M | A | M | J | J | A | S | O | N | D | T\n");
			for (i=0;i<=c-1;i+=1) {
				printf("%s    |%i |%i |%i |%i |%i |%i |%i |%i |%i |%i |%i |%i    | Total-> %i\n",productos[i],ventas[i][0],ventas[i][1],ventas[i][2],ventas[i][3],ventas[i][4],ventas[i][5],ventas[i][6],ventas[i][7],ventas[i][8],ventas[i][9],ventas[i][10],ventas[i][11],totalprod[i]);
				/* Leer Ventas[i,j]; */
				/* Escribir  Productos[i]," ",; */
			}
			printf("Tot X mes|%i |%i |%i |%i |%i |%i |%i |%i |%i |%i |%i |%i\n",totalmes[0],totalmes[1],totalmes[2],totalmes[3],totalmes[4],totalmes[5],totalmes[6],totalmes[7],totalmes[8],totalmes[9],totalmes[10],totalmes[11]);
			printf("+ vendido|%s |%s |%s |%s |%s |%s |%s |%s |%s |%s |%s |%s |\n",productos[maximomes[0]],productos[maximomes[1]],productos[maximomes[2]],productos[maximomes[3]],productos[maximomes[4]],productos[maximomes[5]],productos[maximomes[6]],productos[maximomes[7]],productos[maximomes[8]],productos[maximomes[9]],productos[maximomes[10]],productos[maximomes[11]]);
			break;
		case 7:
			for (i=0;i<=c-1;i+=1) {
				for (j=0;j<=11;j+=1) {
					if (ventas[i][j]>=mayort) {
						mayort = ventas[i][j];
						productomasvendido = i;
						mes = j;
					}
				}
			}
			printf("Producto mas vendido en el año \n");
			printf("Nombre del producto :%s\n",productos[productomasvendido]);
			printf("Mes :%s\n",meses[mes]);
			printf("Cantidad :%i\n",mayort);
			break;
		default:
			printf("Accion no seleccionada\n");
		}
	}
	return 0;
}

