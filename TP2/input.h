#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

int esNumerica(char* cadena);
int esAlfaNumerica(char *str);
int getString(char* cadena, int longitud);
int getInt(int* pResultado);
int myGets(char* cadena, int longitud);
int getFloat(float* pResultado);
int esFlotante(char* cadena);
void strlwrLinux(char* cadena);
int getNombre(char* pResultado, int longitud);
int esNombre(char* cadena,int longitud);


int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);

int utn_getNumeroFloat(float* pResultado,char* mensaje, char* mensajeError,	int minimo, int maximo,	int reintentos);

int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos);

#endif // INPUT_H_INCLUDED
