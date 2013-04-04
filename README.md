#Robot de Búsqueda Heurística implementado en C/C++


* ###  Solución  de los requerimientos:
  * El numero de nodos generados lo tome como la suma de lo que tiene la lista abierta y la lista cerrada.
  * El numero de nodos visitados sería solo el tamaño de la lista cerrada, es decir la suma de nodos desde el origen hasta el destino.
  * La ruta utilizada , pss es la ya calculada.
  * En tiempo utilizado usé un contador en cada ciclo.


##¿Como funciona?

Se usó el algoritmo de búsqueda heurística A*; Se explicará brevemente.

1. Tomar el nodo inicial y asignarlo a nodoAuxiliar.
2. Realizar mientras la lista abierta no este vacía o mientras no se llegue a el objetivo.
  1. Enviar nodoAuxiliar a la lista cerrada.
  2. Descomponer sus nodos adyacentes. Para cada nodo adyacente enviarlo a la lista abierta si y sólo si no se encuentra en esta misma y tampoco en la lista cerrada.
  3. Almacenar en nodoAuxiliar ladirecciónn del padre.
  4. Asignar a nodoAuxiliar el menor de la lista abierta.


##Autores:
Somos estudiantes de la universidad Distrital Francisco José de Caldas. El proyecto fue un trabajo para la materia de inteligencia artificial.

Copyright (C) 2013-today:
* Camilo Ramírez camilortte@hotmail.com, [@camilortte](https://twitter.com/camilortte) on Twitter.
* Jhon Puentes jhonpuentes93@hotmail.com
