#cars="Volvo BMW Seat Fiat RangeRover"
#for i in $cars
#do
#    touch ${i}.cpp
#    touch ${i}.h
#done
g++ main.cpp Circuit.cpp Volvo.cpp BMW.cpp Seat.cpp Fiat.cpp RangeRover.cpp -o main
