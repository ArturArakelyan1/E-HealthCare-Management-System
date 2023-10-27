#ifndef MEDICALHISTORY_H
#define MEDICALHISTORY_H

#include <fstream>

class MedicalHistory {
public:
    MedicalHistory(int patientID, int doctorID);
    ~MedicalHistory();
    MedicalHistory(const MedicalHistory& other);
    MedicalHistory(MedicalHistory&& other) noexcept;
    MedicalHistory& operator=(const MedicalHistory& other);
    MedicalHistory& operator=(MedicalHistory&& other) noexcept;

    void addEntry(const char* entry);
    void printMedicalHistory() const;
    void saveMedicalHistoryToFile(const char* filename) const;

    int getPatientID() const;
    int getDoctorID() const;

private:
    const int m_patientID;
    const int m_doctorID;
    char* m_history;

    void clear();
};

#endif // MEDICALHISTORY_H
