#include "Doctor.h"
int Doctor::s_lastAssignedDoctorID = 0;


Doctor::Doctor(const char* name, const char* specialization, int yearsOfExperience, const char* contactInfo)
    : m_yearsOfExperience(yearsOfExperience), m_doctorID(++s_lastAssignedDoctorID) {
    m_name = copyString(name);
    m_specialization = copyString(specialization);
    m_contactInfo = copyString(contactInfo);
}

Doctor::~Doctor() {
    delete[] m_name;
    delete[] m_specialization;
    delete[] m_contactInfo;
}

Doctor::Doctor(const Doctor& other)
    : m_yearsOfExperience(other.m_yearsOfExperience) ,m_doctorID(other.m_doctorID){
    m_name = copyString(other.m_name);
    m_specialization = copyString(other.m_specialization);
    m_contactInfo = copyString(other.m_contactInfo);
}

Doctor::Doctor(Doctor&& other) noexcept
    : m_name(other.m_name), m_specialization(other.m_specialization), m_yearsOfExperience(other.m_yearsOfExperience), m_contactInfo(other.m_contactInfo), m_doctorID(other.m_doctorID) {
    other.m_name = nullptr;
    other.m_specialization = nullptr;
    other.m_contactInfo = nullptr;
    other.m_yearsOfExperience = 0;
}

Doctor& Doctor::operator=(const Doctor& other) {
    if (this != &other) {
        delete[] m_name; 
        delete[] m_specialization;
        delete[] m_contactInfo; 

        m_name = copyString(other.m_name); 
        m_specialization = copyString(other.m_specialization);
        m_yearsOfExperience = other.m_yearsOfExperience;
        m_contactInfo = copyString(other.m_contactInfo);
    }
    return *this;
}


Doctor& Doctor::operator=(Doctor&& other) noexcept {
    if (this != &other) {
        delete[] m_name;
        delete[] m_specialization;
        delete[] m_contactInfo;

        m_name = other.m_name;
        m_specialization = other.m_specialization;
        m_yearsOfExperience = other.m_yearsOfExperience;
        m_contactInfo = other.m_contactInfo;

        other.m_name = nullptr;
        other.m_specialization = nullptr;
        other.m_contactInfo = nullptr;
        other.m_yearsOfExperience = 0;
    }
    return *this;
}

const char* Doctor::getName() const {
    return m_name;
}

const char* Doctor::getSpecialization() const {
    return m_specialization;
}

int Doctor::getYearsOfExperience() const {
    return m_yearsOfExperience;
}

const char* Doctor::getContactInfo() const {
    return m_contactInfo;
}

int Doctor::getDoctorID() const{
    return m_doctorID;
}

void Doctor::setName(const char* name) {
    delete[] m_name;
    m_name = copyString(name);
}

void Doctor::setSpecialization(const char* specialization) {
    delete[] m_specialization;
    m_specialization = copyString(specialization);
}

void Doctor::setYearsOfExperience(int yearsOfExperience) {
    m_yearsOfExperience = yearsOfExperience;
}

void Doctor::setContactInfo(const char* contactInfo) {
    delete[] m_contactInfo;
    m_contactInfo = copyString(contactInfo);
}

