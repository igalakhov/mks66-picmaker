#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int width = 500;
const int height = 500;

// headers
string convert_to_ppm(int, int, int);

int main(){

    int rects[][4] = {{50, 50, 50, 150},
                       {250, 50, 50, 150},
                       {350, 100, 50, 100},
                       {50, 300, 50, 150},
                       {150, 300, 50, 150},
                       {250, 300, 50, 150},
                       {350, 400, 100, 50}};

    ofstream img_file;
    img_file.open("out.ppm", ofstream::trunc);

    printf("Making image of size [%d by %d]\n", width, height);

    img_file << "P3\n" << width << " " << height << "\n255\n";

    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            bool colored = false;
            for(int k = 0; k < sizeof(rects)/sizeof(*rects); k++){
                if(j >= rects[k][0] and j <= rects[k][2] + rects[k][0]
                    and i >= rects[k][1] and i <= rects[k][1] + rects[k][3]){
                    colored = true;
                    break;
                }
            }

            if(colored)
                img_file << convert_to_ppm((int) 255*i/500, (int) 255*j/500, rand() % 255);
            else
                img_file << convert_to_ppm(255, 255, 255);

        }
        img_file << "\n";
    }

    img_file.close();

    return 0;
}

string convert_to_ppm(int r, int g, int b){
    stringstream ss;
    ss << r << " " << g << " " << b << "  ";
    return ss.str();
}