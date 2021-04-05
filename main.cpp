#include "bitmap.h"
#include <vector>
#include <fstream>


void dump_random_nums(const char *file_name, unsigned int n, unsigned int max_val) {
    std::ofstream out_file(file_name, std::ostream::out);
    const int MAX_LEN = 12;
    char line[MAX_LEN];
    try {
        for (unsigned int i = 0; i < n; i++)  {
            unsigned int r = random() % max_val;
            sprintf(line, "%u\n", r);
            out_file.write(line, strlen(line));
        }
        out_file.write("0\n", 3);
    } catch (...) {
        std::cout << "file write exception" << std::endl;
        out_file.close();
    }
}

int main() {
    const unsigned int MAX_LINE_LEN = 12;
    const unsigned int MAX_VAL = 100;
    std::string file_name = "./test_nums";
    dump_random_nums(file_name.c_str(), 400, MAX_VAL);
    std::ifstream in_file(file_name, std::ifstream::in);
    char line_buff[MAX_LINE_LEN];
    BitMap bm(MAX_VAL);
    while (in_file.getline(line_buff, MAX_LINE_LEN))
        bm.insert(atoi(line_buff));
    std::cout << bm.first_not_appear() << std::endl;
    return 0;
}
