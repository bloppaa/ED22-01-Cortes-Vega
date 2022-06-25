![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Pablo Cortés Vega (20.600.436-3)
* Rodrigo Vega Vásquez (20.881.243-2)

## Resumen 

> Agregar un resumen que describa el trabajo realizado y sus resultados. (Entre 150 y 180 palabras)
> Más cosas...
> El resumen indicarlo como cita con el comando `>`

## 1. Introducción

La primera función de un reporte técnico es plasmar la información necesaria para que otras personas puedan reproducir el sistema propuesto o puedan entender su fucnionamiento . Para cumplir anterior se debe diferenciar claramente entre los artefactos de diseño e implementación. En el caso de un desarrollo tecnológico los algoritmos son importantes como componente de diseño y los programas generalmente son irrelevantes y deben resumidos o agregados en anexos en el documento. Los programas no son importantes en el documento, salvo si se quiere explicar conceptos expecíficos del lenguaje o del algoritmo implementado.

La redacción debe ser formal y de modo impersonal. No se debe utlizar primera persona del singular o plural. Se debe evitar el uso de cualquier calificativo sustituyéndolo siempre utilizando datos concretos y rastreables en documentos o publicaciones a través de referencias bibliográficas. Por ejemplo, no calificar algo como: "muy importante", "sustancial", "muy usadoo" o "mucho mejor".

Las comparaciones deben concretarse con hechos y datos, sin frases ambiguas o términos generales. Por ejemplo, nunca se debe redactar frases como "el método es mejor que el método B". Lo correcto es decir, el error promedio de el método A es de 5 %, correspondiendo a la mitad del error de 10% obtenido utilizando el método B". El tiempo verbal es usualmente presente. No se debe perder de vista que se está explicando ”como hacer algo”, en vez de ”qué se hizo”. Todo aspecto circunstancial es irrelevante para el documento. Por ejemplo, si se ha desarrollado en el laboratorio X, o en el curso Y, con el profesor Z, etc.

### 1.1 Descripción del problema

Dado el laboratorio describir como se entiende el problema bajo sus propias palabras.

### 1.2 Objetivos 

**Objetivo General**

El fin que se desea llegar. (Comenzar con un verbo: "Construir un sistema...", "Desarrollar un sistema...", etc)

**Objetivos específicos**

1. Objetivo 1
2. Objetivo 2
3. Objetivos 3

Los objetivos específicos son acciones específicas que son desarrolladas para lograr cumplir el objetivo general, por ejemplo:

1. Investigar  el  estado  del  arte  de  visión  por  computador  y  audio  para  resolver  tareas de  clasificación unimodal y multimodal aplicado  al  problema  de  reconocimiento  de emociones.
2.  Seleccionar  uno  o  dos  métodos  estudiados  en  el  estado  del  arte  para  la  estimación  de  laemoción utilizando datos unimodales o multimodales.
3.  Implementar los métodos seleccionados utilizando el lenguaje de programación Python y laslibrerías suministradas por Pytorch.
4.  Validar  los  resultados  por  medio  bases  de  datos  especializadas  para  el  desarrollo  deaplicaciones basadas en la estimación de la emoción y que incluyan varios modos de atributoscomo: imágenes, sonido y/o texto.
5.  Proponer  mejoras  a  los  modelos  implementados  para  mejorar  su  desempeño  en  futurasimplementaciones o proyectos de investigación.
6.  Difundir los resultados en medios científicos nacionales o internacionales.

### 1.3 Solución propuesta

Esbozo de la solución propuesta, se espera que esta vaya evolucionando a medida que se avanza en el proyecto.

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


