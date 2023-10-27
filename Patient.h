#ifndef PATIENT_H
#define PATIENT_H
#include "Utils.h"

class Patient {
public:
    Patient(const char* name, const char* dateOfBirth, const char* gender, const char* contactInfo, const char* existingMedicalConditions);
    ~Patient();
    Patient(const Patient& other);
    Patient(Patient&& other) noexcept;
    Patient& operator=(const Patient& other);
    Patient& operator=(Patient&& other) noexcept;

    // Getters
    const char* getName() const;
    const char* getDateOfBirth() const;
    const char* getGender() const;
    const char* getContactInfo() const;
    const char* getExistingMedicalConditions() const;
    int getPatientID() const;

    // Setters
    void setName(const char* name);
    void setDateOfBirth(const char* dateOfBirth);
    void setGender(const char* gender);
    void setContactInfo(const char* contactInfo);
    void setExistingMedicalConditions(const char* existingMedicalConditions);

private:
    char* m_name;
    char* m_dateOfBirth;
    char* m_gender;
    char* m_contactInfo;
    char* m_existingMedicalConditions;
    static int s_lastAssignedPatientID;
    const int m_patientID;
};

#endif // PATIENT_H