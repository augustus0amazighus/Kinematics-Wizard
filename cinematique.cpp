#include <iostream>
#include <cmath>

// دوال للتحويل بين الوحدات
double toKilometers(double meters) {
    return meters / 1000.0;
}

double toMeters(double kilometers) {
    return kilometers * 1000.0;
}

double toCentimeters(double meters) {
    return meters * 100.0;
}

double toMiles(double meters) {
    return meters * 0.000621371;
}

double toMetersFromMiles(double miles) {
    return miles / 0.000621371;
}

// ألوان باستخدام رموز ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

using namespace std;

int main() {
    int choice;
    double s, a, Vi, Vf, d, t;
    string unit_choice;

    cout << GREEN << "WELCOME TO THE CINEMATIQUE CALCULATOR (; " << RESET << endl;
    cout << YELLOW << "1 - Calculate the final velocity (Vf)\n"; 
    cout << "2 - Calculate the distance (d)\n";
    cout << "3 - Calculate the time spent (t)\n";
    cout << "4 - Calculate the acceleration (a)\n";
    cout << "5 - Calculate the spent distance (s)\n";
    cout << WHITE << "Enter your choice: " << RESET;
    cin >> choice;

    switch (choice) {
        case 1: // حساب السرعة النهائية
            cout << CYAN << "Enter acceleration (a), time (t), and initial velocity (Vi):\n" << RESET;
            cin >> a >> t >> Vi;
            Vf = Vi + (a * t);
            cout << MAGENTA << "Final velocity (Vf): " << Vf << " m/s\n" << RESET;
            cout << "Convert to (km, cm, miles)? ";
            cin >> unit_choice;
            if (unit_choice == "km") {
                cout << GREEN << "Vf in kilometers: " << toKilometers(Vf) << " km/s\n" << RESET;
            } else if (unit_choice == "cm") {
                cout << GREEN << "Vf in centimeters: " << toCentimeters(Vf) << " cm/s\n" << RESET;
            } else if (unit_choice == "miles") {
                cout << GREEN << "Vf in miles: " << toMiles(Vf) << " miles/s\n" << RESET;
            }
            break;

        case 2: // حساب المسافة المقطوعة
            cout << CYAN << "Enter initial velocity (Vi), final velocity (Vf), acceleration (a), and time (t):\n" << RESET;
            cin >> Vi >> Vf >> a >> t; 
            d = (0.5 * a * (t * t)) + (Vi * t); // استخدام 0.5 بدلاً من 1/2
            cout << MAGENTA << "Distance (d): " << d << " meters\n" << RESET;
            cout << "Convert to (km, cm, miles)? ";
            cin >> unit_choice;
            if (unit_choice == "km") {
                cout << GREEN << "Distance in kilometers: " << toKilometers(d) << " km\n" << RESET;
            } else if (unit_choice == "cm") {
                cout << GREEN << "Distance in centimeters: " << toCentimeters(d) << " cm\n" << RESET;
            } else if (unit_choice == "miles") {
                cout << GREEN << "Distance in miles: " << toMiles(d) << " miles\n" << RESET;
            }
            break;

        case 3: // حساب الزمن المستغرق
            cout << CYAN << "Enter final velocity (Vf), initial velocity (Vi), and acceleration (a):\n" << RESET;
            cin >> Vf >> Vi >> a;
            if (a == 0) {
                cout << RED << "Error: Acceleration (a) cannot be zero.\n" << RESET;
            } else {
                t = (Vf - Vi) / a;
                cout << MAGENTA << "Time (t): " << t << " seconds\n" << RESET;
            }
            break;

        case 4: // حساب التسارع
            cout << CYAN << "Enter final velocity (Vf), initial velocity (Vi), and time (t):\n" << RESET;
            cin >> Vf >> Vi >> t;
            if (t == 0) {
                cout << RED << "Error: Time (t) cannot be zero.\n" << RESET;
            } else {
                a = (Vf - Vi) / t;
                cout << MAGENTA << "Acceleration (a): " << a << " m/s²\n" << RESET;
            }
            break;

        case 5: // حساب المسافة باستخدام معادلة الحركة
            cout << CYAN << "Enter initial velocity (Vi), acceleration (a), and time (t):\n" << RESET;
            cin >> Vi >> a >> t;
            s = (Vi * t) + (0.5 * a * t * t);
            cout << MAGENTA << "Distance covered (s): " << s << " meters\n" << RESET;
            cout << "Convert to (km, cm, miles)? ";
            cin >> unit_choice;
            if (unit_choice == "km") {
                cout << GREEN << "Distance in kilometers: " << toKilometers(s) << " km\n" << RESET;
            } else if (unit_choice == "cm") {
                cout << GREEN << "Distance in centimeters: " << toCentimeters(s) << " cm\n" << RESET;
            } else if (unit_choice == "miles") {
                cout << GREEN << "Distance in miles: " << toMiles(s) << " miles\n" << RESET;
            }
            break;

        default: // إذا كان الإدخال غير صحيح
            cout << RED << "Invalid choice. Please try again.\n" << RESET;
            break;
    }

    return 0;
}

