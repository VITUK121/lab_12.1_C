#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

char* string_to_char(const string& a) {
    int len = a.length();
    char* res = new char[len + 1];

    for (int i = 0; i < len; i++) {
        res[i] = a[i];
    }
    res[len] = '\0';
    return res;
}

bool isValidForFunction(double value) {
    return value >= 0;
}

void parseFile(const char* name_1, const char* name_2) {
    FILE* file_1;
    file_1 = fopen(name_1, "rb");

    if (file_1 == NULL) {
        FILE* file_1_new = fopen(name_1, "wb");
        fclose(file_1_new);
        cout << "Empty file was created.\n";
        return;
    }

    FILE* file_2;
    file_2 = fopen(name_2, "wb");

    double value;

    while (fread(&value, sizeof(double), 1, file_1) == 1) {
        if (!isValidForFunction(value)) {
            fwrite(&value, sizeof(double), 1, file_2);
        }
    }

    fclose(file_1);
    fclose(file_2);
}

void printFile(const char* name, const string& text) {
    FILE* file = fopen(name, "rb");
    if (!file) {
        cout << "Could not open file for reading: " << name << endl;
        return;
    }

    double value;
    cout << "¬м≥ст " << text << " файлу: ";
    while (fread(&value, sizeof(double), 1, file) == 1) {
        cout << value << " ";
    }

    fclose(file);
    cout << endl;
}

void writeFile(const char* name) {
    FILE* file = fopen(name, "wb");
    if (file == NULL) {
        cout << "Could not open file for writing: " << name << endl;
        return;
    }

    cout << "Add data (type 'end' to finish): \n";
    string data;

    while (true) {
        cout << "> ";
        getline(cin, data);

        /*if (data.empty()) {
            continue;
        }*/

        if (data == "end") {
            break;
        }

        double value;
        try {
            value = stod(data);
        }
        catch (invalid_argument) {
            cout << "Invalid input, only numbers are accepted." << endl;
            continue;
        }

        fwrite(&value, sizeof(double), 1, file);
    }
    fclose(file);
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string n_1;
    string n_2;

    cout << "Enter first filename: "; cin >> n_1;
    cin.ignore();
    cout << "Enter second filename: "; cin >> n_2;
    cin.ignore();

    char* name_1 = string_to_char(n_1);
    char* name_2 = string_to_char(n_2);
    
    writeFile(name_1);

    parseFile(name_1,name_2);

    printFile(name_1,"вх≥дного");
    printFile(name_2,"вих≥дного");
}