#include <stdio.h>

#define LIM 30

typedef struct alumno {
  char nombre[LIM];
  char apellido[LIM];
  int anio;
  int edad;
  float promedio;
}
alumno;

void menu(alumno*, char);

void crearalumno(alumno*, int);
void mostraralumnos(alumno*);
void veralumno(alumno*, int);
void editaralumno(alumno*, int);

char toUpper(char);
void cleanInputBuffer(void);

int main(void) {

  alumno alumnos[LIM];  //vector con hasta 30 alumnos

  printf("Bienvenido a base de datos de alumnos\n");
  menu(&alumnos[0], opc);
  printf("Gracias por usar el software");
  
  return 0;
}

void menu(alumno* pAlumno, char opc){

  static int nalumno = 0;
  static int valumno;
  static char opc;

  do {
    printf("-------------\n");
    printf("-A para ingresar un nuevo alumno\n-B para ver un alumno\n-C para editar un alumno\n-D para salir\n");
    scanf("%c", &opc);
    cleanInputBuffer();
    if ( (opc=='a')||(opc=='A') ){
      crearalumno(&pAlumno[0], nalumno);
      nalumno++;
    }
    else if ((opc=='b')||(opc=='B')){
      mostraralumnos(&pAlumno[0]);
      printf("Que alumno deseas ver: ");
      scanf("%d",&valumno);
      cleanInputBuffer();
      veralumno(&pAlumno[0], valumno);
    }
    else if ((opc=='c')||(opc=='C')){
      mostraralumnos(&pAlumno[0]);
      printf("Que alumno deseas editar: ");
      scanf("%d",&valumno);
      cleanInputBuffer();
      editaralumno(&pAlumno[0], valumno);
    }
    else if ((opc=='d')||(opc=='D')) printf("Opcion invalida\n");
  } while ( (opc!='d')&&(opc!='D') );
}

void mostraralumnos(alumno *pAlumno){
  for(int i = 0; i < LIM; i++){
    if(pAlumno[i].nombre[0] != '\0'){
      printf("#%d Nombre: %s %s\n", i, pAlumno[i].nombre, pAlumno[i].apellido);
    }
  }
  return;
}

void crearalumno(alumno *pAlumno, int indice) {
  printf("Alumno %d:\n",indice);
  printf("Nombre: ");
  scanf("%s",pAlumno[indice].nombre);
  cleanInputBuffer();
  pAlumno[indice].nombre[0] = toUpper(pAlumno[indice].nombre[0]);
  printf("Apellido: ");
  scanf("%s",pAlumno[indice].apellido);
  cleanInputBuffer();
  pAlumno[indice].apellido[0] = toUpper(pAlumno[indice].apellido[0]);
  printf("Año: ");
  scanf("%d", &pAlumno[indice].anio);
  cleanInputBuffer();
  printf("Edad: ");
  scanf("%d", &pAlumno[indice].edad);
  cleanInputBuffer();
  printf("Promedio: ");
  scanf("%f", &pAlumno[indice].promedio);
  cleanInputBuffer();
}

void veralumno(alumno *pAlumno,int valumno) {
  if (valumno >= 0 && valumno < LIM) {
    if (pAlumno[valumno].nombre[0] != '\0') {
      printf("Nombre: %s\n",pAlumno[valumno].nombre);
      printf("Apellido: %s\n",pAlumno[valumno].apellido);
      printf("Año: %d\n",pAlumno[valumno].anio);
      printf("Edad: %d\n",pAlumno[valumno].edad);
      printf("Promedio: %.2f\n",pAlumno[valumno].promedio);
    } else printf("El alumno no existe.\n");
  } else printf("El Indice del alumno no es valido.\n");
}

void editaralumno(alumno *pAlumno, int indice) {
  static alumno alumnox;
  static const char punto[LIM] = ".";
  
  if (pAlumno[indice].nombre[0] == '\0') {
    printf("El alumno no existe.\n");
    return;
  }
  
  printf("Para mantener valor presiona .\n");
  printf("Nombre: %s\n",pAlumno[indice].nombre);
  scanf("%s",alumnox.nombre);
  cleanInputBuffer();
  if (alumnox.nombre[0] != punto[0]) {
    alumnox.nombre[0] = toUpper(alumnox.nombre[0]);
    int i = 0;
    while ((pAlumno[indice].nombre[i] = alumnox.nombre[i]) != '\0') i++;
  }
  
  printf("Apellido: %s\n",pAlumno[indice].apellido);
  scanf("%s",alumnox.apellido);
  cleanInputBuffer();
  if (alumnox.apellido[0] != punto[0]) {
    alumnox.apellido[0] = toUpper(alumnox.apellido[0]);
    int i = 0;
    while ((pAlumno[indice].apellido[i] = alumnox.apellido[i]) != '\0') i++;
  }
  
  printf("Año: %d\n",pAlumno[indice].anio);
  scanf("%d",&alumnox.anio);
  cleanInputBuffer();
  if (alumnox.anio != 0) {
    pAlumno[indice].anio = alumnox.anio;
  }
  
  printf("Edad: %d\n",pAlumno[indice].edad);
  scanf("%d",&alumnox.edad);
  cleanInputBuffer();
  if (alumnox.edad != 0){
    pAlumno[indice].edad = alumnox.edad;
  }
  
  printf("Promedio: %.2f\n",pAlumno[indice].promedio);
  scanf("%f",&alumnox.promedio);
  cleanInputBuffer();
  if (alumnox.promedio != 0){
    pAlumno[indice].promedio = alumnox.promedio;
  }
  
}

void cleanInputBuffer(void){
  static int c;
  while ((c = getchar()) != -1 && c != '\n') {}
}

char toUpper(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 'a' + 'A';
  }
  return c;
}
