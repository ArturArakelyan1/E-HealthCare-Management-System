#include "MedicalHistory.h"
#include "Utils.h"
#include <iostream>

MedicalHistory::MedicalHistory(int patientID, int doctorID)
    : m_patientID(patientID), m_doctorID(doctorID), m_history(nullptr) {}

MedicalHistory::~MedicalHistory() {
    clear();
}

MedicalHistory::MedicalHistory(const MedicalHistory& other)
    : m_patientID(other.m_patientID), m_doctorID(other.m_doctorID), m_history(copyString(other.m_history)) {}

MedicalHistory::MedicalHistory(MedicalHistory&& other) noexcept
    : m_patientID(other.m_patientID), m_doctorID(other.m_doctorID), m_history(other.m_history) {
    other.m_history = nullptr;
}

MedicalHistory& MedicalHistory::operator=(const MedicalHistory& other) {
    if (this != &other) {
        clear();
        m_history = copyString(other.m_history);
        // m_patientID and m_doctorID are const and are not assigned
    }
    return *this;
}

MedicalHistory& MedicalHistory::operator=(MedicalHistory&& other) noexcept {
    if (this != &other) {
        clear();
        m_history = other.m_history;
        other.m_history = nullptr;
    }
    return *this;
}

void MedicalHistory::addEntry(const char* entry) {
    if (m_history == nullptr) {
        m_history = copyString(entry);
    } else {
        char* newHistory = new char[strlen(m_history) + strlen(entry) + 2];
        strcpy(newHistory, m_history);
        strcat(newHistory, "\n");
        strcat(newHistory, entry);
        delete[] m_history;
        m_history = newHistory;
    }
}

void MedicalHistory::printMedicalHistory() const {
    std::cout << "Medical History for Patient ID: " << m_patientID << ", Doctor ID: " << m_doctorID << std::endl;
    if (m_history && strlen(m_history) > 0) {
        std::cout << m_history << std::endl;
    } else {
        std::cout << "No entries in medical history." << std::endl;
    }
}


void MedicalHistory::saveMedicalHistoryToFile(const char* filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        return;
    }
    outFile << "Medical History for Patient ID: " << m_patientID << ", Doctor ID: " << m_doctorID << std::endl;
    if (m_history && strlen(m_history) > 0) {
        outFile << m_history << std::endl;
    } else {
        outFile << "No entries in medical history." << std::endl;
    }
    outFile.close();
    std::cout << "Medical history saved to " << filename << std::endl;
}


int MedicalHistory::getPatientID() const {
    return m_patientID;
}

int MedicalHistory::getDoctorID() const {
    return m_doctorID;
}

void MedicalHistory::clear() {
    delete[] m_history;
    m_history = nullptr;
}
