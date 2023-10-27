#include "HealthCareSystem.h"
#include <iostream>

HealthCareSystem::HealthCareSystem() {}

HealthCareSystem::~HealthCareSystem() {}

void HealthCareSystem::registerDoctor(const char* name, const char* specialization, int yearsOfExperience, const char* contactInfo) {
    doctors.emplace_back(name, specialization, yearsOfExperience, contactInfo);
}

void HealthCareSystem::registerPatient(const char* name, const char* dateOfBirth, const char* gender, const char* contactInfo, const char* existingMedicalConditions) {
    patients.emplace_back(name, dateOfBirth, gender, contactInfo, existingMedicalConditions);
}

void HealthCareSystem::addMedicalHistory(int patientID, int doctorID, const char* entry) {
    // Check if patient and doctor exist
    auto patientIt = std::find_if(patients.begin(), patients.end(), [patientID](const Patient& p) { return p.getPatientID() == patientID; });
    auto doctorIt = std::find_if(doctors.begin(), doctors.end(), [doctorID](const Doctor& d) { return d.getDoctorID() == doctorID; });

    if (patientIt != patients.end() && doctorIt != doctors.end()) {
        // Check if medical history already exists
        auto historyIt = std::find_if(medicalHistories.begin(), medicalHistories.end(), [patientID](const MedicalHistory& mh) { return mh.getPatientID() == patientID; });

        if (historyIt != medicalHistories.end()) {
            // Medical history exists, add entry
            historyIt->addEntry(entry);
        } else {
            // Medical history does not exist, create new
            medicalHistories.emplace_back(patientID, doctorID);
            medicalHistories.back().addEntry(entry);
        }
    } else {
        std::cerr << "Error: Patient or Doctor not found." << std::endl;
    }
}


void HealthCareSystem::generateReport(int patientID) const {
    bool historyFound = false;

    for (const auto& history : medicalHistories) {
        if (history.getPatientID() == patientID) {
            history.printMedicalHistory();
            historyFound = true;
            break; // Assuming one medical history per patient, we can break once found
        }
    }

    if (!historyFound) {
        std::cout << "No medical history found for patient with ID " << patientID << std::endl;
    }
}

void HealthCareSystem::saveReport(int patientID, const char* filename) const {
    bool historyFound = false;

    for (const auto& history : medicalHistories) {
        if (history.getPatientID() == patientID) {
            history.saveMedicalHistoryToFile(filename);
            historyFound = true;
            break; // Assuming one medical history per patient, we can break once found
        }
    }

    if (!historyFound) {
        std::cerr << "Error: No medical history found for patient with ID " << patientID << std::endl;
    }
}

