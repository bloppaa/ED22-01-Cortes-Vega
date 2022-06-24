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
    // No se recibe ningún rectángulo nuevo
    if (rects.empty()) {
        // Itera la lista de personas e incrementa la cantidad de frames
        // desaparecidos de cada uno en 1
        Node<Person>* it = people->front();
        while (it != nullptr) {
            Person* p = it->data;
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
}