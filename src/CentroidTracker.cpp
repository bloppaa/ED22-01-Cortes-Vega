#include "CentroidTracker.h"
#include "Set.h"

#include <cmath>

using namespace std;

CentroidTracker::CentroidTracker(int maxFrames) {
    nextPersonID = 0;
    people = new LinkedList<Person>();
    this->maxFrames = maxFrames;
}

void CentroidTracker::regist(int x, int y) {
    Person* p = new Person(nextPersonID, x, y);
    people->pushBack(p);
    nextPersonID++;
}

void CentroidTracker::deregist(int personID) {
    people->remove(personID);
}

/**
 * @brief Obtiene una lista con los centroides de cada persona
 * 
 * @param people La lista de personas
 * @return std::vector<std::pair<int, int>> La lista de centroides
 */
vector<pair<int, int>> getCentroids(LinkedList<Person>* people) {
    vector<pair<int, int>> centroids;
    // Itera la lista de personas
    Node<Person>* it = people->front();
    while (it != nullptr) {
        Person* p = it->data;
        pair<int, int> centroid = make_pair(p->getX(), p->getY());
        centroids.push_back(centroid);
    }
    return centroids;
}

/**
 * @brief Calcula la distancia euclidiana entre dos puntos 2D.
 * 
 * @param p1 Punto 1
 * @param p2 Punto 2
 * @return float La distancia entre los puntos.
 */
float distance(pair<int, int> p1, pair<int, int> p2) {
    int x = (p2.first - p1.first);
    int y = (p2.second - p1.second);
    return sqrt(x*x + y*y);
}

/**
 * @brief Obtiene la distancia euclidiana entre cada centroide anterior y
 * cada centroide actual. Por principio multiplicativo, la cantidad de
 * distancias será (N x M).
 * 
 * @param inputCentroids Lista de centroides actuales
 * @param peopleCentroids Lista de centroides anteriores
 * @return std::vector<std::vector<float>>
 */
vector<vector<float>> getDistances(
    vector<pair<int, int>> inputCentroids,
    vector<pair<int, int>> peopleCentroids
) {
    // Matriz (N x M) con las distancias
    vector<vector<float>> distances;
    // Loop exterior
    for (pair<int, int> p1 : inputCentroids) {
        // Distancias entre el p1 actual y cada uno de los p2
        vector<float> tempDist;
        // Loop interior
        for (pair<int, int> p2 : peopleCentroids) {
            tempDist.push_back(distance(p1, p2));
        }
        // Añadir la lista de distancias del punto actual a la lista
        // general de distancias
        distances.push_back(tempDist);
    }
    return distances;
}

/**
 * @brief Retorna una lista con los valores mínimos de cada fila de una matriz
 * 
 * @param distances La matriz con los valores
 * @return vector<float> 
 */
vector<float> findMin(vector<vector<float>> distances) {
    // Inicializar la lista de mínimos
    vector<float> mins;

    for (vector<float> v : distances) {
        float min = v[0];
        // Búsqueda del mínimo
        for (float i : v) {
            if (i < min)
                min = i;
        }
        mins.push_back(min);
    }
    return mins;
}

/**
 * @brief Retorna una lista con los índices que ordenarían la lista original.
 * 
 * @param v La lista original
 * @return vector<int> La lista con los índices
 */
vector<int> argsort(vector<float> v) {
    // Lista de valores con sus índices
    vector<pair<float, int>> pairs;
    int i = 0;
    for (float f : v) {
        pairs.push_back(make_pair(f, i++));
    }

    // Sort con respecto a los valores
    sort(pairs.begin(), pairs.end(), [](auto& a, auto& b) {
        return a.first < b.first;
    });

    // Lista con los índices
    vector<int> indices;
    for (pair<float, int> p : pairs) {
        indices.push_back(p.second);
    }
    return indices;
}

/**
 * @brief Retorna una lista con los índices de los valores mínimos de cada
 * fila de una matriz.
 * 
 * @param distances La matriz con los valores
 * @return vector<int> La lista con los índices
 */
vector<int> argmin(vector<vector<float>> distances) {
    // Inicializar la lista de índices
    vector<int> args;

    for (vector<float> v : distances) {
        float min = v[0];
        int argMin = 0;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] < min) {
                min = v[i];
                argMin = i;
            }
        }
        args.push_back(argMin);
    }
    return args;
}

/**
 * @brief Ordena una lista según los índices.
 * 
 * @param indices 
 * @return vector<int> 
 */
vector<int> indexsort(vector<int> nums, vector<int> indices) {
    vector<int> result;
    for (int i : indices) {
        result.push_back(nums[i]);
    }
    return result;
}

LinkedList<Person>* CentroidTracker::update(vector<cv::Rect> rects) {
    // Verifica que no se haya recibido ningún rectángulo nuevo
    if (rects.empty()) {
        // Itera la lista de personas e incrementa la cantidad de frames
        // desaparecidos de cada uno en 1
        Node<Person>* it = people->front();
        while (it != nullptr) {
            Person* p = it->data;
            // Incrementa la cantidad de frames desaparecidos en 1
            p->setFramesDissappeared(p->getFramesDissappeared() + 1);

            // Si la persona supera la cantidad máxima de frames que puede
            // estar desaparecida se elimina de la lista
            if (p->getFramesDissappeared() > maxFrames)
                deregist(p->getID());

            it = it->next;
        }
        // Retorna antes ya que no hay información nueva para actualizar
        return people;
    }
    
    // Crea una matriz de (n x 2) para guardar los centroides
    vector<pair<int, int>> inputCentroids;

    // Calcula los centroides de cada rectángulo y los añade a la matriz
    for (cv::Rect r : rects) {
        int cX = (int)((r.x + r.width) / 2);
        int cY = (int)((r.y + r.height) / 2);

        inputCentroids.push_back(make_pair(cX, cY));
    }

    // Si no hay personas registradas, registramos cada una de ellas con los
    // centroides calculados anteriormente
    if (people->isEmpty()) {
        for (pair<int, int> c : inputCentroids) {
            regist(c.first, c.second);
        }
    }
    // Si hay personas registradas, entonces necesitamos hacer coincidir
    // cada centroide nuevo con los centroides actuales
    else {
        // Obtiene los centroides actuales de cada persona
        vector<pair<int, int>> peopleCentroids = getCentroids(people);

        // Obtiene las distancias entre los centroides actuales y los
        // centroides nuevos
        vector<vector<float>> distances = getDistances(peopleCentroids, inputCentroids);

        // (1) Busca el valor mínimo de cada fila
        // (2) Crea una lista con los índices de estos valores
        vector<int> rows = argsort(findMin(distances));

        // (1) Busca el índice del valor mínimo de cada fila
        // (2) Ordena esta lista según <rows>
        vector<int> cols = argmin(distances);
        cols = indexsort(cols, rows);

        // ----------------------------------------------------------------

        Set usedRows = Set();
        Set usedCols = Set();

        for (int i = 0; i < rows.size(); i++) {
            if (usedRows.contains(rows[i]) || usedCols.contains(cols[i])) {
                continue;
            }
            
            Person* person = people->get(rows[i]);
            person->setX(inputCentroids[cols[i]].first);
            person->setY(inputCentroids[cols[i]].second);
            person->setFramesDissappeared(0);

            usedRows.add(rows[i]);
            usedCols.add(cols[i]);
        }

        Set unusedRows = Set(distances.size()).difference(usedRows);
        Set unusedCols = Set(distances[0].size()).difference(usedCols);

        if (distances.size() > distances[0].size()) {
            S_Node *node = unusedRows.front();
            while (node != nullptr) {
                Person* person = people->get(node->data);
                person->setFramesDissappeared(person->getFramesDissappeared() + 1);

                if (person->getFramesDissappeared() > maxFrames)
                    deregist(person->getID());
                
                node = node->next;
            }
        }
        else {
            S_Node *node = unusedCols.front();
            while (node != nullptr) {
                pair<float, float> centroid = inputCentroids[node->data];
                regist(centroid.first, centroid.second);

                node = node->next;
            }
        }
    }
    return people;
}