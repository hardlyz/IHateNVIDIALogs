#include <filesystem>
#include <iostream>
#include <windows.h>

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

using namespace std;
namespace fs = std::filesystem;


void menu()
{
    system("cls");
    std::cout << "I Hate NVIDIA Logs Menu\n";
    std::cout << "==============================================\n";
    std::cout << "1. Remove NVIDIA recently launched programs\n";
    std::cout << "==============================================\n";
    std::cout << "2. Exit\n";
    std::cout << ">";


}

int get_variant(int count) {
    int variant;
    char s[100];
    scanf("%s", s);

    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect input. Try again: ");
        scanf("%s", s);
    }

    return variant;
}

void remove_logs() {
    system("cls");
    string path = "C:\\ProgramData\\NVIDIA Corporation\\Drs";
    string file_name = "nvAppTimestamps";
    if (fs::exists(path))
    {
        for (auto& entry : fs::directory_iterator(path))
        {
            string file_name_in_dir = entry.path().string();
            if (file_name_in_dir.find(file_name) != string::npos)
            {
                fs::remove(entry.path());
                cout << "NVIDIA Log file was deleted" << endl;
                Sleep(2500);
                menu();
            }
        }
    }
}

int main() {
    int variant;

    do {
        menu();

        variant = get_variant(3);

        switch (variant) {
        case 1:
            remove_logs();
            break;
        }

        if (variant != 2)
            system("pause");
    } while (variant != 2);

    return 0;
}


