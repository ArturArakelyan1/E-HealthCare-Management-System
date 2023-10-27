#ifndef DOCTOR_H
#define DOCTOR_H
#include "Utils.h"


class Doctor {
public:
    Doctor(const char* name, const char* specialization, int yearsOfExperience, const char* contactInfo);
    ~Doctor();
    Doctor(const Doctor& other);
    Doctor(Doctor&& other) noexcept;
    Doctor& operator=(const Doctor& other);
    Doctor& operator=(Doctor&& other) noexcept;

    // Getters
    const char* getName() const;
    const char* getSpecialization() const;
    int getYearsOfExperience() const;
    const char* getContactInfo() const;
    int getDoctorID() const;

    // Setters
    void setName(const char* name);
    void setSpecialization(const char* specialization);
    void setYearsOfExperience(int yearsOfExperience);
    void setContactInfo(const char* contactInfo);

private:
    char* m_name;
    char* m_specialization;
    int m_yearsOfExperience;
    char* m_contactInfo;
    static int s_lastAssignedDoctorID;
    const int m_doctorID;
};

#endif // DOCTOR_H