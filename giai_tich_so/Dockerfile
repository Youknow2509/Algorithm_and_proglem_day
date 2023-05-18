FROM ubuntu::latest

RUN apt-get -y update && apt-get install -y

RUN apt-get install clang

COPY . /urs/src/clang_run_file_cpp

WORKDIR /urs/src/clang_run_file_cpp

RUN g++ -o file_run main.cpp

CMD [ "./file_run" ]