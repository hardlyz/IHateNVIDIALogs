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
    cout << "= I Hate NVIDIA Logs Menu\n";
    cout << "= THIS SOFTWARE IS FREE, IF YOU PAID MONEY FOR IT, YOU HAVE BEEN SCAMMED!\n";
    cout << "===============================================\n";
    cout << "= 1. Remove NVIDIA recently launched programs =\n";
    cout << "= 2. Open NVIDIA Logs folder                  =\n";
    cout << "===============================================\n";
    cout << "=\n";
    cout << "= 3. Exit\n";
    cout << "= > ";


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
        case 2:
            system("explorer C:\\ProgramData\\\NVIDIA Corporation\\Drs");
            break;
        }

        if (variant != 3)
            system("pause");
    } while (variant != 3);

    return 0;
}


