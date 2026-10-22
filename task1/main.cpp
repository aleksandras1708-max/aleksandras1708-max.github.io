#include <iostream>

int main(int argc, char* argv[]) {
    

    char* first = argv[1];
    char* second = argv[2];

    bool first_minus = false;
    bool second_minus = false;

    int first_pos = 0;
    int second_pos = 0;

    
    if (first[first_pos] == '-') {
        first_minus = true;
        ++first_pos;
    } else if (first[first_pos] == '+') {
        ++first_pos;
    }

    if (second[second_pos] == '-') {
        second_minus = true;
        ++second_pos;
    } else if (second[second_pos] == '+') {
        ++second_pos;
    }

    int sravnenie = 0;

    if (first_minus != second_minus) {
        if (first_minus) {
            sravnenie = -1;
        } else {
            sravnenie = 1;
        }
    } else {
        int first_cel = first_pos;
        int second_cel = second_pos;

        while (first[first_pos] != '.' && first[first_pos] != '\0') {
            ++first_pos;
        }

        while (second[second_pos] != '.' && second[second_pos] != '\0') {
            ++second_pos;
        }

        
        int first_cel_len = first_pos - first_cel;
        int second_cel_len = second_pos - second_cel;

        if (first_cel_len < second_cel_len) {
            sravnenie = -1;
        } else if (first_cel_len > second_cel_len) {
            sravnenie = 1;
        } else {
            for (int i = 0; i < first_cel_len; ++i) {
                int first_d = first[first_cel + i];
                int second_d = second[second_cel + i];

                if (first_d < second_d) {
                    sravnenie = -1;
                    break;
                } else if (first_d > second_d) {
                    sravnenie = 1;
                    break;
                }
                
            }
        }

        int first_drob = first_pos;
        int second_drob = second_pos;

        if (first[first_drob] == '.') {
            ++first_drob;
        }
        if (second[second_drob] == '.') {
            ++second_drob;
        }

        int first_drob_len = 0;
        int second_drob_len = 0;

        while (first[first_drob + first_drob_len] != '\0') {
            ++first_drob_len;
        }
        while (second[second_drob + second_drob_len] != '\0') {
            ++second_drob_len;
        }

        if (sravnenie == 0) {
            int drob_len = (first_drob_len > second_drob_len) ? first_drob_len : second_drob_len;

           
            for (int i = 0; i < drob_len; ++i) {
                char first_d = '0';
                char second_d = '0';

                if (i < first_drob_len) {
                    first_d = first[first_drob + i];
                }
                if (i < second_drob_len) {
                    second_d = second[second_drob + i];
                }

                if (first_d < second_d) {
                    sravnenie = -1;
                    break;
                } else if (first_d > second_d) {
                    sravnenie = 1;
                    break;
                }
            }
        }

        if (first_minus) {
            sravnenie = -sravnenie;
        }
    }

    if (sravnenie < 0) {
        std::cout << "less\n";
    } else if (sravnenie > 0) {
        std::cout << "greater\n";
    } else {
        std::cout << "equal\n";
    }

    return 0;
}
