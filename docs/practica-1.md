Sistemas Operativos – Grado en Ingeniería del Software

Práctica obligatoria 1

Programación en C

Curso 2026-27

Descripción

En  esta  práctica  se  abordará  el  problema  de  implementar  una  biblioteca  (también  llamada
librería) en el lenguaje de programación C. El grupo de prácticas deberá realizar las siguientes
actividades:

•  Escribir una biblioteca en lenguaje C que muestre N líneas por la salida estándar, con

tres funcionalidades diferentes según la función invocada.

•  Escribir  un  programa  de  prueba  que  sirva  para  comprobar  el  funcionamiento  de  las

funciones de biblioteca.

Las funciones principales que se implementarán en la biblioteca serán las siguientes:

Función int head(int N):

Se comporta de la misma forma que head(1) leyendo de la entrada estándar, es decir, muestra
las  N  primeras  líneas  en  la  salida  estándar  recibidas  por  la  entrada  estándar.  Se  recomienda
revisar el mandato head mediante el uso del mandato man y probar en la bash dicho mandato.

Función int tail(int N):

Se comporta de la misma forma que tail(1) leyendo de la entrada estándar, es decir, muestra
las  N  últimas  líneas  en  la  salida  estándar  recibidas  por  la  entrada  estándar.  Se  recomienda
revisar el mandato tail mediante el uso del mandato man y probar en la bash dicho mandato.

Función int longlines(int N):

Muestra las N líneas más largas recibidas de mayor a menor, o todas ellas si hay menos de N
líneas, por la entrada estándar de forma ordenada en la salida estándar.

El grupo de prácticas deberá realizar tres ficheros:

•

libreria.c: fichero con el código de las funciones pedidas.

•

test.c:  programa  de  prueba  de  las  funciones  implementadas  en  la  librería.  Este
programa deberá aceptar uno o dos argumentos para poder realizar todas las pruebas
posibles:

test -<función> [número de líneas]

donde

-<función> será una de las tres posibles, dejando libertad al alumno para especificarla
como desee, pero teniendo en cuenta que este argumento siempre empezará con un
guion.

[número  de  líneas]  será  un  número  entero  positivo  mayor  de  0.  Este  argumento  es
opcional,  y  si  no  se  le  pasa  al  programa  test  se  entenderá  que  se  desea  mostrar  10
líneas.

•  compila.sh: script que genere la librería y compile el programa test, enlazando con la

librería generada. El nombre de la librería generada deberá ser liblibreria.a

El código de los 3 ficheros estará debidamente comentado.

El  cuarto  fichero  con  las  cabeceras  de  las  funciones  de  biblioteca  (libreria.h)  se  entrega  en
aula virtual y no se debe modificar.

Objetivos parciales

Los objetivos parciales perseguidos en esta práctica son los siguientes:

-

Ser  capaz  de  reconocer  argumentos  en  el  programa  principal  (test)  que  llame  a  la
biblioteca (1.5 puntos).

-  Realizar un control adecuado de errores (1.5 puntos)

-

Ejecución correcta de la funcionalidad de la biblioteca. (5 puntos)

-  Utilización de memoria dinámica (2 puntos)

Nota:  las  puntuaciones  para  cada  objetivo  parcial  son  las  puntuaciones  máximas  que  se
pueden obtener si se cumplen esos objetivos.

Nota:  no  se  debe  hacer  un  programa  separado  para  cada  objetivo,  sino  un  único  programa
genérico que cumpla con todos los objetivos simultáneamente.

Entrega de prácticas

La  entrega  de  prácticas  se  hará  a  través  del  Campus  Virtual  en  las  fechas  anunciadas  en  el
mismo. Se debe entregar tres archivos fuente: uno con el código de la librería libreria.c, otro
fichero test.c con un programa de ejemplo que haga uso de la librería construida (tal y como se
ha  especificado  antes),  y  un  último  fichero  compila.sh  que  al  ejecutarse  genere  la  librería,
compile  el  test.c  y  lo  enlace  con  la  librería.  Dichos  ficheros  deben  estar  debidamente

comentados. Además de los mismos se debe entregar una memoria de la práctica en formato
pdf. La memoria debe realizarse partiendo de la plantilla WORD aportada en el aula virtual y
debe incluir:

Índice de contenidos

•
•  Autores
•  Descripción  del  código:

implementadas.

incluyendo  descripción  de

las  principales

funciones

•  Comentarios  personales:  incluyendo  problemas  encontrados,  críticas  constructivas,

propuesta de mejoras y evaluación del tiempo dedicado.

•  No incluir código fuente
•  NO DESCUIDE LA CALIDAD DE LA MEMORIA DE SU PRÁCTICA. Aprobar la memoria es
tan  imprescindible  para  aprobar  la  práctica,  como  el  correcto  funcionamiento  del
código C desarrollado. Si al evaluar la memoria se considera que no alcanza el mínimo
admisible, la práctica se considerará SUSPENSA.

IMPORTANTE:  Todos  los  archivos  solicitados  (fuentes  y  memoria)  deberán  empaquetarse  en
un único  archivo comprimido  en  formato ZIP llamado  practica1.zip y entregarse a través del
Campus Virtual pinchando en el enlace correspondiente.

Evaluación de la práctica

La práctica se evaluará comprobando el correcto funcionamiento de los distintos objetivos, y
valorando la simplicidad del código, los comentarios, la óptima gestión de recursos, la gestión
de errores y la calidad de la memoria. El profesor solicitará una defensa oral de la práctica.

A la hora de codificar las funciones pedidas en ambos apartados, se deberán respetar una serie
de normas de estilo:

•

Las variables locales de las funciones se declararán inmediatamente después de la llave
de comienzo del cuerpo de la  misma.  Se penalizará la declaración de variables entre
sentencias ejecutables de las funciones.

•  Cuando  se  declare  una  variable  de  tipo  array,  su  tamaño  deberá  ser  conocido  en
tiempo  de  compilación.  Si  se  quiere  utilizar  un  array  de  tamaño  variable,  deberá
crearse en memoria dinámica mediante las funciones correspondientes (malloc, calloc
o  realloc).  La  memoria  dinámica  solicitada  deberá  liberarse  (free)  antes  de  salir  del
programa.

•

Las operaciones sobre strings (copia, comparación, duplicación, concatenación, etc) se
realizarán en lo posible mediante las funciones indicadas en string.h (ver referencias a
la biblioteca de C en el Campus Virtual).

•  En  general,  se  penalizará  el  uso  de  construcciones  propias  de  C++.  Dichas

construcciones se comentarán durante las clases de explicación de la práctica.

•  Al compilar el código fuente, deberá producirse el menor número posible de avisos o

warnings (mejor que no se produzca ninguno).

•  El formato de salida de las funciones head y tail deberá ser el mismo que los mandatos

correspondientes, head(1) y tail (1).

El  incumplimiento  de  estas  normas  de  estilo,  así  como  de  otras  normas  que  puedan  ser
anunciadas por el profesor a través del Campus Virtual, conllevará una penalización en la nota
obtenida a partir del baremo indicado en el apartado de objetivos parciales.

Defensa oral de la práctica

Después  de  entregar  la  práctica,  cada  alumno  será  convocado  de  forma  individual  para
realizar una defensa oral de su práctica, en fecha y lugar indicados por el equipo docente de la
asignatura.

En la defensa oral de la práctica, el alumno:

•  Compilará y montará el ejecutable de su práctica desde la línea de mandatos de Linux.
•  Ejecutará  y  demostrará  el  funcionamiento  de  su  práctica,  de  acuerdo  con  las

indicaciones del profesor.

•  Responderá a cuestiones relativas al código fuente de su práctica.

La  defensa  oral  de  la  práctica  tiene  influencia  sobre  la  nota  final  obtenida  en  la  misma,  de
forma que puede mejorar o  empeorar la nota parcial calculada a partir del cumplimiento de
objetivos, las normas de estilo del código fuente y la memoria. Si el desempeño del alumno en
la  defensa  oral  no  alcanza  el  mínimo  nivel  admisible,  la  práctica  en  su  conjunto  se
considerará  SUSPENSA,  pudiéndose  incluso  solicitar  al  alumno  que  entregue  una  práctica
totalmente nueva para la siguiente convocatoria.

Autoría de la práctica

La práctica se debe realizar en grupos de 2 personas como máximo.


