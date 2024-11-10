#include <iostream>  
#include <TFile.h>   // Библиотека рут для работы с файлами рут
#include <TTree.h>   // Библиотека рут для работы с деревьями данных

// Функция для анализа данных из файла ROOT
void analyze_root_file(const char* filename) {
   
    TFile* file = TFile::Open(filename);   //Открываю файл и даю указатель на него
    
    if (!file || file->IsZombie()) {     //Проверка на успешно открытый файл, если не открыт то ошибка, если открыт частично то метод Зомби выведет значение true что так же приведет к ошибке
        std::cerr << "Error opening file: " << filename << std::endl; 
        return; 
    }

    
    TTree* tree = (TTree*)file->Get("tree_name");   // Извлекаю дерево данных (TTree) из файла, далее можно использовать любое название для дерева, я оставил по дефолту
    
    if (!tree) {     // Проверка, существует ли дерево вообще
        std::cerr << "Error: Tree not found in file." << std::endl; 
        file->Close(); 
        return; 
    }

    
    float energy; // Переменная для хранения энергии
    int emitter_type; // Переменная для хранения типа излучателя

    
    tree->SetBranchAddress("energy", &energy);      //установка адресов для переменных, чтобы рут правильно помещала данные
    tree->SetBranchAddress("emitter_type", &emitter_type); 

    
    Long64_t nEntries = tree->GetEntries();     //все количество записей в дереве
    
    for (Long64_t i = 0; i < nEntries; i++) {
        tree->GetEntry(i); // Извлекаем данные для каждой текущей записи, переходим к другой

        
        std::cout << "Energy: " << energy << ", Emitter Type: " << emitter_type << std::endl;     //вывод значения энергии и соответсвующей ему тип излучателя. На след неделю могу добавить логику с проверкой с теор значениями

        
    }

    file->Close();
}


int main(int argc, char** argv) {
   
    if (argc < 2) {   //тут проверка правильности передачи файла по аргументам, то есть если их меньше 2х то ошибка
        std::cerr << "Usage: " << argv[0] << " <root_file>" << std::endl; 
    }

    
    analyze_root_file(argv[1]);     //вызов написанной функции
    return 0; 
}


//создать гистограмму, заполнить ее циклом

//гамма Е 4 - 40 гэв
//гамма Тетта рисуем от 50мк до 4 мл радиан
//ивент триггеред это

//триггер тайп = 2 и триггер тайп = 3