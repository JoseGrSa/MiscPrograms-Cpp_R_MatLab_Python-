#include "Busqueda.h"

int main()
{

Busqueda busqueda1;

busqueda1.genVector();
busqueda1.setNum();

busqueda1.busquedaSecuencial(busqueda1.elementos,busqueda1.numeros);
busqueda1.busquedaSecuencialOrdenada1(busqueda1.elementos,busqueda1.numeros);
busqueda1.busquedaBinaria(busqueda1.elementos,busqueda1.numeros);










}