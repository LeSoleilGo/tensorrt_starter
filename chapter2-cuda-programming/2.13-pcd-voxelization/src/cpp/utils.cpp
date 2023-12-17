#include "utils.hpp"
#include <math.h>
#include <random>
#include <iostream>
#include <fstream>

void initMatrix(float* data, int size, int low, int high, int seed) {
    srand(seed);
    for (int i = 0; i < size; i ++) {
        // data[i] = float(rand()) * float(high - low) / RAND_MAX;
        data[i] = (float)i;
    }
}

void printMat(float* data, int size) {
    for (int i = 0; i < size; i ++) {
        printf("%.8lf", data[i]);
        if (i != size - 1) {
            printf(", ");
        } else {
            printf("\n");
        }
    }
}

void compareMat(float* h_data, float* d_data, int size) {
    double precision = 1.0E-4;
    /* 
     * 这里注意，浮点数运算时CPU和GPU之间的计算结果是有误差的
     * 一般来说误差保持在1.0E-4之内是可以接受的
    */
    for (int i = 0; i < size; i ++) {
        if (abs(h_data[i] - d_data[i]) > precision) {
            int y = i / size;
            int x = i % size;
            printf("Matmul result is different\n");
            printf("cpu: %.8lf, gpu: %.8lf, cord:[x=%d, y=%d]\n", h_data[i], d_data[i], x, y);
            break;
        }
    }
}

std::string getPrefix(std::string file_path) {
    std::string prefix;
    int pos1 = file_path.find('/');
    int pos2 = file_path.rfind('.');
    prefix = file_path.substr(pos1, pos2 - pos1);
    return prefix;
}

// 使用流读取数据
int loadData(const char *file, void **data, unsigned int *length)
{
    std::fstream dataFile(file, std::ifstream::in);

    if (!dataFile.is_open()) {
        std::cout << "Can't open files: "<< file<<std::endl;
        return -1;
    }

    unsigned int len = 0;
    dataFile.seekg (0, dataFile.end);
    len = dataFile.tellg();
    dataFile.seekg (0, dataFile.beg);

    char *buffer = new char[len];
    if (buffer==NULL) {
        std::cout << "Can't malloc buffer."<<std::endl;
        dataFile.close();
        exit(EXIT_FAILURE);
    }

    dataFile.read(buffer, len);
    dataFile.close();

    *data = (void*)buffer;
    *length = len;
    return 0;  
}
