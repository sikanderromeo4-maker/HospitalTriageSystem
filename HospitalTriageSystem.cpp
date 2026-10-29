#include <iostream>
#include "ERPatientList.h"

PatientNode* RegisterPatient(int id, std::string name, int severity) {
    PatientNode* p = new PatientNode;
    p->patientID = id;
    p->name = name;
    p->severityLevel = severity;
    p->next = nullptr;
    return p;
}

int main() {
    ERPatientList erWaitlist;

    // Patients arriving at the ER
    erWaitlist.InsertPatientAt(RegisterPatient(201, "Ali", 3), 0);
    erWaitlist.InsertPatientAt(RegisterPatient(202, "Sara", 4), 1);
    erWaitlist.InsertPatientAt(RegisterPatient(203, "Ahmed", 2), 2);
    
    std::cout << "--- INITIAL ER WAITLIST ---";
    erWaitlist.DisplayWaitlist();

    // Critical patient arrives (Insert at head)
    erWaitlist.AddPatient(RegisterPatient(200, "Zainab", 1));
    std::cout << "\n--- CRITICAL PATIENT ARRIVES (Inserted at Head) ---";
    erWaitlist.DisplayWaitlist();

    // Patient at index 3 condition worsens, swap with index 1
    erWaitlist.SwapPatients(1, 3);
    std::cout << "\n--- SWAPPING PATIENTS (Index 1 and 3) ---";
    erWaitlist.DisplayWaitlist();

    // Sort to ensure most critical are treated first
    erWaitlist.SortBySeverity();
    std::cout << "\n--- SORTING BY SEVERITY (Most Critical First) ---";
    erWaitlist.DisplayWaitlist();

    // Triage nurse realizes they need to check the least critical first (Reverse)
    erWaitlist.ReverseWaitlist();
    std::cout << "\n--- REVERSING WAITLIST ---";
    erWaitlist.DisplayWaitlist();

    // Treat the first patient
    PatientNode* treated = erWaitlist.TreatPatient();
    if (treated != nullptr) {
        std::cout << "\n--- TREATING PATIENT: " << treated->name << " (ID: " << treated->patientID << ") ---\n";
        delete treated;
    }
    
    std::cout << "\n--- FINAL WAITLIST ---";
    erWaitlist.DisplayWaitlist();

    return 0;
}