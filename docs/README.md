![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Pablo Cortés Vega (20.600.436-3)
* Rodrigo Vega Vásquez (20.881.243-2)

## Resumen 

> Actualmente, se ha podido traspasar en casi su totalidad el algoritmo utilizado en el tutorial de Python para poder realizar la detección y el seguimiento a las personas. Esto conlleva crear nuevos métodos y comprender el algoritmo, ya que hay mucho métodos que no existen en C++ o que son distintos a Python. Por el momento no se ha podido probar ya que se requiere depuración.


## 1. Introducción

Bien es sabido que la informática y la computación aporta en la mayoría de los aspectos de la vida. De todas las áreas en que la informática ayuda, uno de ellos es la seguridad mediante la utilización de cámaras y otros sensores para poder detectar a los individuos que circulan por un lugar, o para poder registrar distintos sucesos que ocurren en un lugar específico. Pero poco sirven todas las cámaras y sensores si es que no se utilizan con un software que sea acorde para poder ser de utilidad. Debido a esto, durante este documento se vera como se realizo un proyecto de detección de personas y conteo de estas, para poder ayudar a la tarea de un guardia de mantener la seguridad de su trabajo. 

### 1.1 Descripción del problema

La empresa ACME requiere de un sistema de vigilancia para determinar cuantas personas entran y salen de una zona de un edificio. Todo esto para poder ayudar al guardia en su tarea de mantener la seguridad dentro del edificio. La empresa ACME requiere saber cuantas personas entran y salen, distinguir entre las personas y también saber quienes se repiten más. Es decir, requerimos crear un software que, mediante video, sea capaz de detectar cuantas personas entran y salen de un lugar, y que sea capaz de distinguir entre ellas.

### 1.2 Objetivos 

**Objetivos**

Desarrollar un sistema que permita detectar, seguir y diferenciar distintas personas en un video:

1.	Mediante la librería OpenCV, programar un software que sea capaz de detectar personas en una imagen/video de manera correcta y fiable.
2.	Mediante la detección de personas, crear un sistema de seguimiento en base a su posición el cual sea capaz de diferenciar entre las distintas personas que se encuentran en la imagen.
3.	Mediante el seguimiento diferenciado de personas, poder contabilizar cuantas personas traspasan una zona específica (Entrada y salida de personas)
4.	Implementar, mediante OpenCV, un sistema en el cual el software sea capaz de reconocer a una persona que haya sido detectada anteriormente.


### 1.3 Solución propuesta
Para poder desarrollar este código, se dividió inicialmente en 3 partes. Inicialmente, se programo las listas enlazadas las cuales guardaran la información de las personas/detecciones que vaya haciendo el software. Una vez hecho esto, se prosiguió con la detección de personas en cada imagen, para luego aplicarla a un video completo dividendo el video en distintas imágenes. Finalmente, para poder diferenciar entre las personas que se encuentran en una misma imagen, se utilizo un algoritmo que en base a los centros de detección, determina la distancia con respecto a la imagen anterior y a los nuevos centros de detección, de esta manera poder hacer un seguimiento a una persona que se encuentre en el video.

## 2. Materiales y métodos

La solución se implementó mediante el uso de un tutorial en Python sobre cómo contar personas usando un algoritmo de *seguimiento de centroides*. Dicho código no usa las estructuras de datos propuestas anteriormente, por lo que fue necesario refactorizar dicho código, no obstante, la lógica siguió siendo la misma.

### 2.1 Instalación

Se usó la librería OpenCV para hacer las detecciones de personas correspondientes. En cuanto a la IDE, el proyecto se desarrolló en Visual Studio Code junto con CMake debido a la complejidad del proyecto.

### 2.2 Diseño 

El programa se construyó siguiendo el paradigma de Orientación al Objeto. Hay dos
clases principales, en las cuales se apoya todo el proyecto: `Person` y `CentroidTracker`. Además, para el almacenamiento de datos, se implementaron los TDA `LinkedList` y `Set`.

### 2.3 Implementación

La clase `Person` guarda algunos datos como las coordenadas actuales del centroide
de la persona y la cantidad de frames que dicha persona se encuentra fuera del video. Sin embargo, casi toda la algoritmia se encuentra encapsulada dentro de la clase `CentroidTracker`.

Esta clase tiene tres métodos principales: *registrar* una persona, *eliminar* una persona y *actualizar* una persona.

```cpp
class CentroidTracker
{
private:
    int nextPersonID;
    LinkedList<Person>* people;
    int maxFrames;

public:
    CentroidTracker(int maxFrames);

    void regist(int x, int y);

    void deregist(int personID);

    LinkedList<Person>* update(std::vector<Rect>& rects);
};
```

## 3. Resultados obtenidos

## 4. Conclusiones

# Anexos

## Anexo A: Instalación librerías OpenCV

## Anexo B: Instalación de IDE y configuración librerías OpenCV

# Referencia

Indicar los libros, páginas web, documentos, etc. Utilizados en el trabajo. Por ejemplo:

1. MONTERO, J.,Metodos matemáticos aplicados a la ganadería.3aed. Sevilla: Ediciones de la pradera,2007.
2. LVARADO,   J.   P.,¿Qué   debe   contener   un   artículo   científico?.http://www.ie.tec.ac.cr/palvarado/pmwiki/index.php/MSc/Art\%c3\%adculoCient\%c3\%adfico. Fe-cha de acceso:13/Nov/2018


