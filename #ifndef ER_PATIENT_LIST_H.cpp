#ifndef ER_PATIENT_LIST_H
#define ER_PATIENT_LIST_H

#include "PatientNode.h"
#include <iostream>

class ERPatientList {
private:
    PatientNode* head;
    int count;

    PatientNode* GetNodeAt(int index) {
        PatientNode* current = head;
        for (int i = 0; i < index && current != nullptr; i++) {
            current = current->next;
        }
        return current;
    }

    void SwapData(PatientNode* a, PatientNode* b) {
        std::swap(a->patientID, b->patientID);
        std::swap(a->name, b->name);
        std::swap(a->severityLevel, b->severityLevel);
    }

public:
    ERPatientList();
    ERPatientList(const ERPatientList& other);
    ERPatientList& operator=(const ERPatientList& other);
    ~ERPatientList();

    void AddPatient(PatientNode* patient); // Insert at head
    PatientNode* TreatPatient(); // Remove from head
    void InsertPatientAt(PatientNode* patient, int index);
    PatientNode* RemovePatientAt(int index);
    void SwapPatients(int index1, int index2);
    void SortBySeverity();
    void ReverseWaitlist();
    void DisplayWaitlist();
    bool IsEmpty();
    bool IsNotEmpty();
};

#endif