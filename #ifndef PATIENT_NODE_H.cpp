#ifndef PATIENT_NODE_H
#define PATIENT_NODE_H

#include <string>
#include <utility>

struct PatientNode {
    int patientID;
    std::string name;
    int severityLevel; // 1 (Critical) to 5 (Stable)
    PatientNode* next;
};

#endif