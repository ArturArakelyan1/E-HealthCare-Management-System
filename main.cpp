#include "HealthCareSystem.h"
#include <iostream>

int main() {
    HealthCareSystem system;

    system.registerDoctor("Dr. Gregory House", "Cardiology", 15, "123-456-7890");
    system.registerPatient("William Shockley", "February 13, 1910", "Male", "098-765-4321", "Cancer");

    system.addMedicalHistory(1, 1, "Patient has a history of heart disease.");
    system.generateReport(1);

    system.saveReport(1, "Shockle_MedicalHistory.txt");

    return 0;
}
