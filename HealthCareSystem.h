#ifndef HEALTHCARESYSTEM_H
#define HEALTHCARESYSTEM_H
#include "Doctor.h"
#include "Patient.h"
#include "MedicalHistory.h"
#include <vector>

class HealthCareSystem {
public:
    HealthCareSystem();
    ~HealthCareSystem();

    void registerDoctor(const char* name, const char* specialization, int yearsOfExperience, const char* contactInfo);
    void registerPatient(const char* name, const char* dateOfBirth, const char* gender, const char* contactInfo, const char* existingMedicalConditions);
    void addMedicalHistory(int patientID, int doctorID, const char* entry);
    void generateReport(int patientID) const;
    void saveReport(int patientID, const char* filename) const;

private:
    std::vector<Doctor> doctors;
    std::vector<Patient> patients;
    std::vector<MedicalHistory> medicalHistories;
};
#endif // HEALTHCARESYSTEM_H