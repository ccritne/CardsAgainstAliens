mkdir -p build
for file in include/*.cpp; do g++ -c $file -o build/$(basename $file .cpp).o -std=c++17 -I include/headers -I lib/SFML/include; done
g++ -c src/main.cpp -o build/main.o -std=c++17 -I include/headers -I lib/SFML/include 
g++ build/*.o -o aliens.o -std=c++17 -L lib/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
export LD_LIBRARY_PATH=lib/SFML-3.0.0/lib
./aliens