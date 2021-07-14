#include <iostream>
#include <fstream>

//int main(){}
//int main(int argc, const char* argv[]) {
int main(int argc, const char** argv) { // 1TBS
 // - стек и куча
 // - malloc, calloc
    int *arr = (int *) malloc(10 * sizeof(int)); //(void *)
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    int *ar2 = (int *) calloc(10, sizeof(int)); //(void *)
    for (int i = 0; i < 10; i++) {
        std::cout << ar2[i] << " ";
    }

 // - free
    free(arr);
    arr = (int *) malloc(10 * sizeof(int)); //(void *)

 // - realloc
    arr = (int *) realloc(arr, 20 * sizeof(int)); //(void *)
    std::cout << std::endl;

 // - аргументы вызова программы
    std::cout << argc << std::endl;

    for (int i = 0; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    std::cout << std::endl;
    
 // - new, delete
    int *ar3 = new int[20];
    int **ar4 = new int*[5];

    delete [] ar3;
    
 // - потоки stdin stdout stderr
    std::string word;
//    std::cin >> word;
//    getLine();
    std::cout << word << "Hello";

 // - файлы базовые чтение/запись
    // fopen() fprintf() fscanf()
    // FILE *f = fopen("hello.txt", "w");

    std::ofstream fos("hello.txt", std::ofstream::app);
    fos << " ivan " << "\n";
    fos.close();

    std::ifstream fis("hello.txt");
    fis >> word;
    //fis.getLine(word);
    char c;
    fis.get(c);

    while (!fis.eof()) {
        ////
    }
    
    return 0; 
}
