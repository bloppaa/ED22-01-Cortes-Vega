#include "CentroidTracker.h"

CentroidTracker::CentroidTracker(int maxFrames) {
    nextPersonID = 0;
    people = new LinkedList<Person>();
    this->maxFrames = maxFrames;
}

void CentroidTracker::regist(int x, int y) {
    Person* p = new Person(nextPersonID, x, y);
    people->push(p);
    nextPersonID++;
}

void CentroidTracker::deregist(int personID) {
    people->remove(personID);
}

LinkedList<Person>* CentroidTracker::update(std::vector<cv::Rect> rects) {
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
    std::vector<std::pair<int, int>> inputCentroids;

    // Calcula los centroides de cada rectángulo y los añade a la matriz
    for (cv::Rect r : rects) {
        int cX = (int)((r.x + r.width) / 2);
        int cY = (int)((r.y + r.height) / 2);

        inputCentroids.push_back(std::make_pair(cX, cY));
    }

    // Si no hay personas registradas, registramos cada una de ellas con los
    // centroides calculados anteriormente
    if (people->isEmpty()) {
        for (std::pair<int, int> c : inputCentroids) {
            regist(c.first, c.second);
        }
    }
    // Si hay personas registradas, entonces necesitamos hacer coincidir
    // cada centroide nuevo con los centroides de las personas actuales
    else {
        void;
    }
}