#include "ERPatientList.h"

ERPatientList::ERPatientList() {
    head = nullptr;
    count = 0;
}

ERPatientList::ERPatientList(const ERPatientList& other) {
    head = nullptr;
    count = 0;
    PatientNode* current = other.head;
    while (current != nullptr) {
        PatientNode* copy = new PatientNode{current->patientID, current->name, current->severityLevel, nullptr};
        InsertPatientAt(copy, count);
        current = current->next;
    }
}

ERPatientList& ERPatientList::operator=(const ERPatientList& other) {
    if (this == &other) return *this;
    while (!IsEmpty()) delete TreatPatient();
    PatientNode* current = other.head;
    while (current != nullptr) {
        PatientNode* copy = new PatientNode{current->patientID, current->name, current->severityLevel, nullptr};
        InsertPatientAt(copy, count);
        current = current->next;
    }
    return *this;
}

ERPatientList::~ERPatientList() {
    while (!IsEmpty()) delete TreatPatient();
}

void ERPatientList::AddPatient(PatientNode* patient) {
    if (patient == nullptr) return;
    patient->next = head;
    head = patient;
    count++;
}

PatientNode* ERPatientList::TreatPatient() {
    if (IsEmpty()) return nullptr;
    PatientNode* patient = head;
    head = head->next;
    patient->next = nullptr;
    count--;
    return patient;
}

void ERPatientList::InsertPatientAt(PatientNode* patient, int index) {
    if (patient == nullptr) return;
    if (index < 0) index = 0;
    if (index > count) index = count;
    
    if (index == 0) {
        AddPatient(patient);
        return;
    }
    PatientNode* previous = GetNodeAt(index - 1);
    patient->next = previous->next;
    previous->next = patient;
    count++;
}

PatientNode* ERPatientList::RemovePatientAt(int index) {
    if (IsEmpty()) return nullptr;
    if (index < 0) index = 0;
    if (index >= count) index = count - 1;
    
    if (index == 0) return TreatPatient();
    
    PatientNode* previous = GetNodeAt(index - 1);
    PatientNode* toRemove = previous->next;
    previous->next = toRemove->next;
    toRemove->next = nullptr;
    count--;
    return toRemove;
}

void ERPatientList::SwapPatients(int index1, int index2) {
    if (index1 == index2) return;
    PatientNode* first = GetNodeAt(index1);
    PatientNode* second = GetNodeAt(index2);
    if (first != nullptr && second != nullptr) {
        SwapData(first, second);
    }
}

// Sort by Severity (1 is Critical, 5 is Stable)
void ERPatientList::SortBySeverity() {
    for (PatientNode* i = head; i != nullptr; i = i->next) {
        for (PatientNode* j = i->next; j != nullptr; j = j->next) {
            if (i->severityLevel > j->severityLevel) { // Smaller number = higher priority
                SwapData(i, j);
            }
        }
    }
}

void ERPatientList::ReverseWaitlist() {
    PatientNode* previous = nullptr;
    PatientNode* current = head;
    PatientNode* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

void ERPatientList::DisplayWaitlist() {
    PatientNode* current = head;
    int index = 0;
    std::cout << "\nPos\tID\tName\t\tSeverity\n";
    std::cout << "--------------------------------------------------\n";
    while (current != nullptr) {
        std::cout << index << "\t" << current->patientID << "\t" 
                  << current->name << "\t\tLevel " << current->severityLevel << "\n";
        current = current->next;
        index++;
    }
    std::cout << "Total patients in ER: " << count << "\n";
}

bool ERPatientList::IsEmpty() { return head == nullptr; }
bool ERPatientList::IsNotEmpty() { return head != nullptr; }